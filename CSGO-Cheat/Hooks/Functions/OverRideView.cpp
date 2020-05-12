#include "../Hooks.hpp"
#include "../../Cheat/Interfaces.hpp"
#include "../../Cheat/Features/Features.hpp"

namespace Cheat::Core::Hooks
{
	void __fastcall overrideView(REGISTERS, SDK::Interface::ViewSetup* viewSetup)
	{
		if (Interface::getInterfaces.engine->isConnected() && Interface::getInterfaces.engine->isInGame())
		{
			Visuals::viewmodel(viewSetup);
		}

		GET_ORIGINAL_FUNCTION(clientMode, 18, void(__thiscall*)(std::uintptr_t, SDK::Interface::ViewSetup*), ecx, viewSetup);
	}
}