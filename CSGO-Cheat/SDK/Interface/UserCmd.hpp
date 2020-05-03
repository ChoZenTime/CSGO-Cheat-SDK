#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/game/shared/usercmd.h

#include "../Misc/Macros.hpp"
#include "../Misc/Vector.hpp"

namespace Cheat::SDK::Interface
{
	struct UserCmd
	{
		PAD(pad, 4) {};

		std::int32_t commandNumber {};
		std::int32_t tickCount     {};

		Misc::Vector viewAngles   {};
		Misc::Vector aimDirection {};

		float forwardMove {};
		float sideMove    {};
		float upMove      {};

		std::int32_t  buttons       {};
		std::uint8_t  impulse       {};
		std::int32_t  weaponSelect  {};
		std::int32_t  weaponSubtype {};
		std::int32_t  randomSeed    {};
		std::uint16_t mouseX        {};
		std::uint16_t mouseY        {};

		bool hasBeenPredicted {};
	};
}
