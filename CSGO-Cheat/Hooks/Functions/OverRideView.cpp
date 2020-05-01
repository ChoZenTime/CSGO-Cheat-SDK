#include "../Hooks.hpp"

namespace Cheat::Core::Hooks
{
	void __fastcall overrideView(REGISTERS, SDK::Interface::ViewSetup* viewSetup)
	{
		if (Interface::getInterfaces.engine->isConnected() && Interface::getInterfaces.engine->isInGame())
		{
			
		}

		GET_ORIGINAL_FUNCTION(clientMode, 18, void(__thiscall*)(std::uintptr_t, SDK::Interface::ViewSetup*), ecx, viewSetup);
	}
}