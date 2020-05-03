#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/engine/ivdebugoverlay.h

#include "../Misc/Macros.hpp"
#include "../Misc/Vector.hpp"

namespace Cheat::SDK::Interface
{
	struct DebugOverlay
	{
		VFUNC(screenPosition(const Misc::Vector& point, Misc::Vector& screen), 13, std::int32_t(__thiscall*)(void*, const Misc::Vector&, Misc::Vector&), point, screen)
	};
}
