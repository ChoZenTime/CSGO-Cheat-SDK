#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/game/client/cliententitylist.h

#include "Entity.hpp"
#include "../Misc/Macros.hpp"

namespace Cheat::SDK::Interface
{
	struct ClientEntity
	{
		VFUNC(getClientEntity(const std::int32_t index), 3, Entity* (__thiscall*)(void*, std::int32_t), index);
		VFUNC(getClientEntityFromHandle(void* handle), 7, Entity* (__thiscall*)(void*, void*), handle);
		VFUNC(getHighestEntityIndex(), 8, std::int32_t(__thiscall*)(void*));
		VFUNC(setMaxEntities(const std::int32_t entity), 9, void(__thiscall*)(void*, std::int32_t), entity);
		VFUNC(getMaxEntites(), 10, std::int32_t(__thiscall*)(void*));
	};
}