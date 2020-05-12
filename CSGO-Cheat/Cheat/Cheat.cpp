#include "Cheat.hpp"
#include "Configuration.hpp"
#include "../Hooks/Hooks.hpp"
#include "../Memory/Memory.hpp"
#include "../Menu/Menu.hpp"

void Cheat::Core::detach(const HMODULE module)
{
	Hooks::destroy();
	
	FreeLibraryAndExitThread(module, EXIT_SUCCESS);
}

void Cheat::Core::attach(const HMODULE module)
{
	Interface::Interfaces {};
	Memory::Memory {};

	SDK::Misc::getNetvarTree = std::make_unique<SDK::Misc::NetvarTree>();
	SDK::Misc::setupRenderFunctions();
	SDK::Misc::setupInputFunctions();

	Hooks::create();

	Menu::render();

	fgui::handler::call_notification("[ - ] FAIL PRIVATE - INJECTED", fgui::animation_type::LINEAR);
	
	while (!GetAsyncKeyState(Configuration::exitThreadKey)) {}

	fgui::handler::call_notification("[ - ] FAIL PRIVATE - UNINJECTED", fgui::animation_type::LINEAR);

	while (!fgui::handler::doneRendering()) {}

	detach(module);
}