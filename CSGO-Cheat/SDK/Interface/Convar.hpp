#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/tier1/convar.h

#include "UtlVector.hpp"
#include "../Misc/Macros.hpp"

namespace Cheat::SDK::Interface
{
	struct Convar
	{
		VFUNC(getFloat(), 12, float(__thiscall*)(void*))
		VFUNC(getInt(), 13, std::int32_t(__thiscall*)(void*))
		VFUNC(setValue(const char* value), 14, void(__thiscall*)(void*, const char*), value)
		VFUNC(setValue(const float value), 15, void(__thiscall*)(void*, float), value)
		VFUNC(setValue(const std::int32_t value), 16, void(__thiscall*)(void*, std::int32_t), value)

		PAD(pad1, 24);

		std::add_pointer_t<void()> changeCallback;

		Convar* parent;

		const char* defaultValue;

		char* string;

		PAD(pad2, 28);

		UtlVector<void()> onChangeCallbacks {};
	};
}