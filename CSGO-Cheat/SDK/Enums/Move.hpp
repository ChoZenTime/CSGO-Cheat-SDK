#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/const.h

namespace Cheat::SDK::Enum
{
	enum class Move
	{
		None = 0,
		Isometric,
		Walk,
		Step,
		Fly,
		FlyGravity,
		Physics,
		Push,
		NoClip,
		Ladder,
		Observer,
		Custom,
		Last = Custom,
		MaxBits = 4,
		Max
	};
}
