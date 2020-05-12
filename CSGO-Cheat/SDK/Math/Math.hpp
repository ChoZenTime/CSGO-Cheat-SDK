#pragma once

#include "../Misc/Vector.hpp"

namespace Math
{
	Cheat::SDK::Misc::Vector calculateAngle(const Cheat::SDK::Misc::Vector& source, const Cheat::SDK::Misc::Vector& destination);
	float distance(const Cheat::SDK::Misc::Vector& source, const Cheat::SDK::Misc::Vector& destination);
}

namespace Constant
{
	const float pi = 3.14159265359f;
}