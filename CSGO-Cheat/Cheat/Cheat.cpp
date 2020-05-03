#include "Cheat.hpp"
#include "Configuration.hpp"
#include "Memory.hpp"
#include "../Hooks/Hooks.hpp"
#include "../Menu/Menu.hpp"

void Cheat::Core::detach(LPVOID const* thread)
{
	Hooks::destroy();
	
	FreeLibraryAndExitThread(static_cast<HMODULE>(*thread), EXIT_SUCCESS);
}

void Cheat::Core::attach(LPVOID const* thread)
{
	Interface::Interfaces{};
	Memory::Memory {};

	SDK::Misc::getNetvarTree = std::make_unique<SDK::Misc::NetvarTree>();
	SDK::Misc::setupRenderFunctions();
	SDK::Misc::setupInputFunctions();

	Hooks::create();

	Menu::render();

	fgui::handler::call_notification("[ - ] Success", fgui::animation_type::LINEAR);

	while (!GetAsyncKeyState(Configuration::exitThreadKey)) {}

	fgui::handler::call_notification("[ - ] Detached", fgui::animation_type::LINEAR);

	detach(thread);
}