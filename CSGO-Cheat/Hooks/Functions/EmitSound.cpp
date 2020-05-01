#include "../Hooks.hpp"

namespace Cheat::Core::Hooks
{
	void __fastcall emitSound(REGISTERS, const SDK::Interface::SoundData soundData)
	{
		GET_ORIGINAL_FUNCTION(sound, 5, void(__thiscall*)(std::uintptr_t, SDK::Interface::SoundData), ecx, soundData);
	}
}