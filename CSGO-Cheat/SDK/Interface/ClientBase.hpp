#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/cdll_int.h

#include "ClientClass.hpp"
#include "../Misc/Macros.hpp"

// TODO: Remove this

#define VFUNC(functionName, index, type, ...) \
	auto functionName \
	{ \
		return Cheat::SDK::Misc::vfuncFromIndex<type>(this, index)(this, __VA_ARGS__); \
	};

namespace Cheat::SDK::Interface
{
	struct BaseClient
	{
	    VFUNC(getAllClasses(), 8, ClientClass* (__thiscall*)(void*))
		VFUNC(dispatchUserMessage(const std::int32_t message, const std::int32_t firstArg, const std::int32_t secondArg, void* data), 38, bool(__thiscall*)(void*, std::int32_t, std::uint32_t, std::uint32_t, void*), message, firstArg, secondArg, data)
	};
}