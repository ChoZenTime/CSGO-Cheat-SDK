#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/inputsystem/iinputsystem.h

#include "../Enums/AnalogCode.hpp"
#include "../Misc/Macros.hpp"

namespace Cheat::SDK::Interface
{
	struct InputSystem
	{
		VFUNC(isButtonDown       (const std::int32_t keyCode),        15, bool(__thiscall*)(void*, std::int32_t), keyCode)
		VFUNC(getAnalogValue     (const Enum::AnalogCode analogCode), 18, std::int32_t(__thiscall*)(void*, Enum::AnalogCode), analogCode)
		VFUNC(getAnalogDelta     (const Enum::AnalogCode analogCode), 19, std::int32_t(__thiscall*)(void*, Enum::AnalogCode), analogCode)
		VFUNC(buttonCodeToString (const std::int32_t buttonCode),     40, const char* (__thiscall*)(void*, std::int32_t), buttonCode)
	};
}
