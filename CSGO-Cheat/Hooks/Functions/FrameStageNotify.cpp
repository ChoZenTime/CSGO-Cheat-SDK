#include "../Hooks.hpp"

namespace Cheat::Core::Hooks
{
	void __fastcall frameStageNotify(REGISTERS, const SDK::Enum::ClientFrameStage clientFrameStage)
	{
		GET_ORIGINAL_FUNCTION(client, 37, void(__thiscall*)(std::uintptr_t, SDK::Enum::ClientFrameStage), ecx, clientFrameStage);
	}
}