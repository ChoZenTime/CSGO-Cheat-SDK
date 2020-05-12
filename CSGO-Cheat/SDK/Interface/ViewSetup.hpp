#pragma once

#include "../Misc/Macros.hpp"

namespace Cheat::SDK::Interface
{
	struct ViewSetup
	{
		std::uint8_t pad[176];

		float viewModelFov;
	};
}
