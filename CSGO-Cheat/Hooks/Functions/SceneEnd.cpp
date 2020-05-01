#include "../Hooks.hpp"

namespace Cheat::Core::Hooks
{
	void __fastcall sceneEnd(REGISTERS)
	{
		GET_ORIGINAL_FUNCTION(renderView, 9, void(__thiscall*)(std::uintptr_t), ecx);
	}
}