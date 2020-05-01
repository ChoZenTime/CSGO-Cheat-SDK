#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/inputsystem/AnalogCode.h

namespace Cheat::SDK::Enum
{
	enum class AnalogCode
	{
		Invalid = -1,
		MouseX = 0,
		MouseY,
		MouseXY,
		MouseWheel,
		Last = 10
	};
}
