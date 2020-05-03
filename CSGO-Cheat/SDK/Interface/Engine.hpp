#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/cdll_int.h

#include "PlayerInfo.hpp"
#include "../Misc/Macros.hpp"
#include "../Misc/Vector.hpp"

namespace Cheat::SDK::Interface
{
	struct Engine
	{
		VFUNC(getPlayerInfo(const std::int32_t entity, PlayerInfo& info), 8, bool(__thiscall*)(void*, std::int32_t, PlayerInfo&), entity, info)
		VFUNC(getPlayerForUserId(const std::int32_t entity), 9, std::int32_t(__thiscall*)(void*, std::int32_t), entity)
		VFUNC(getLocalPlayer(), 12, std::int32_t(__thiscall*)(void*))
		VFUNC(getViewAngles(Misc::Vector& angle), 18, void(__thiscall*)(void*, Misc::Vector&), angle)
		VFUNC(setViewAngles(Misc::Vector& angle), 19, void(__thiscall*)(void*, Misc::Vector&), angle)
		VFUNC(getMaxClients(), 20, std::int32_t(__thiscall*)(void*))
		VFUNC(isInGame(), 26, bool(__thiscall*)(void*))
		VFUNC(isConnected(), 27, bool(__thiscall*)(void*))
		VFUNC(isTakingScreenshot(), 92, bool(__thiscall*)(void*))
		VFUNC(isHltv(), 93, bool(__thiscall*)(void*))
		VFUNC(executeClientCmd(const char* cmd), 108, void(__thiscall*)(void*, const char*), cmd)
	};
}


