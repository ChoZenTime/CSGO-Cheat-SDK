#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/dt_common.h

namespace Cheat::SDK::Enum
{
	enum class SendPropType
	{
		Int = 0,
		Float,
		Vector,
		VectorXY,
		String,
		Array,
		DataTable,
		Int64,
		Num
	};
}