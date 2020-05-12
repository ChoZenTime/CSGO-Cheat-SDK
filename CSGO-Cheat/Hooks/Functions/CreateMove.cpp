#include "../Hooks.hpp"
#include "../../Cheat/Interfaces.hpp"
#include "../../Cheat/Features/Features.hpp"

namespace Cheat::Core::Hooks
{
	bool __fastcall createMove(REGISTERS, const float frame, SDK::Interface::UserCmd* cmd)
	{
		if (!cmd || !cmd->commandNumber)
		{
			GET_ORIGINAL_FUNCTION(clientMode, 24, bool(__thiscall*)(std::uintptr_t, float, SDK::Interface::UserCmd*), ecx, frame, cmd);
		}

		if (Interface::getInterfaces.engine->isConnected() && Interface::getInterfaces.engine->isInGame())
		{
			Misc::noFlash();
			Misc::bunnyHop(cmd);
			Misc::autoStrafe(cmd);
			Misc::moonWalk(cmd);
			Misc::edgeJump(cmd);
			Misc::noDuckCooldown(cmd);
		}

		return false;
	}
}
