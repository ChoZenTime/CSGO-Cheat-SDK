#include "../Hooks.hpp"
#include "../../Cheat/Features/Features.hpp"

namespace Cheat::Core::Hooks
{
	void __fastcall paintTraverse(REGISTERS, const std::int32_t panelName, const bool paint, const bool force)
	{
		GET_ORIGINAL_FUNCTION(panel, 41, void(__thiscall*)(std::uintptr_t, std::int32_t, bool, bool), ecx, panelName, paint, force);

		static auto copy = 0;

		if (!copy && !std::strcmp(Interface::getInterfaces.panel->getPanelName(panelName), "FocusOverlayPanel"))
		{
			copy = panelName;
		}
		
		if (panelName != copy) return;

		if (Interface::getInterfaces.engine->isConnected() && Interface::getInterfaces.engine->isInGame())
		{
			Features::window();
		}
	}
}
