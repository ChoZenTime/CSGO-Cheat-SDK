#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/icvar.h

#include "Convar.hpp"
#include "../Misc/Macros.hpp"

namespace Cheat::SDK::Interface
{
	struct Cvar
	{
		VFUNC(findCvar(const char* cvar), 15, Convar* (__thiscall*)(void*, const char*), cvar)
	};
}