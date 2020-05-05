#pragma once

#include "../Misc/Macros.hpp"

namespace Cheat::SDK::Interface
{
	struct ViewSetup
	{
		std::uint8_t pad[176];

		float viewModelFov;

		std::uint8_t pad1[32];

		float nearViewModel;
		float farViewModel;
		float aspectRatio;
	};
}
