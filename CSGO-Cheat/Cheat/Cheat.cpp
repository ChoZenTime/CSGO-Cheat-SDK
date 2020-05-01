#include "Cheat.hpp"
#include "Configuration.hpp"
#include "Memory.hpp"
#include "../Hooks/Hooks.hpp"
#include "../Menu/Menu.hpp"

#include <thread>

BOOL WINAPI Cheat::Core::detach()
{
	Hooks::destroyHooks();

	MessageBoxA(nullptr, "[-] Exited thread", "Cheat", 0);

	return EXIT_SUCCESS;
}

DWORD WINAPI Cheat::Core::attach(LPVOID const thread)
{
	Interface::Interfaces{};
	Memory::Memory{};

	SDK::Misc::getNetvarTree = std::make_unique<SDK::Misc::NetvarTree>();
	SDK::Misc::setupRenderFunctions();
	SDK::Misc::setupInputFunctions();

	Hooks::createHooks();

	Menu::render();

	fgui::handler::call_notification("[-] Successfully injected", fgui::animation_type::LINEAR);

	// while (!Menu::checkBox["#unload_cheat_checkbox"]->get_bool())
	while (!GetAsyncKeyState(Configuration::exitThreadKey)) {}

	detach();
	
	FreeLibraryAndExitThread(static_cast<HMODULE>(thread), EXIT_SUCCESS);
}