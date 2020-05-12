#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/game/shared/cam_thirdperson.h

#include "../Misc/Macros.hpp"
#include "../Misc/Vector.hpp"

namespace Cheat::SDK::Interface
{
	struct Input
	{
		PAD(pad1, 12) {};

		bool isTrackIrAvailable {};
		bool isMouseInitialized {};
		bool isMouseActive      {};

		PAD(pad2, 158) {};

		bool isCameraInThirdPerson {};

		PAD(pad3, 1) {};

		Misc::Vector cameraOffset {};
	};
}
