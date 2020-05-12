#include "Math.hpp"
#include "../Misc/Vector.hpp"

#include <corecrt_math.h>

float Math::distance(const Cheat::SDK::Misc::Vector &source, const Cheat::SDK::Misc::Vector &destination)
{
	Cheat::SDK::Misc::Vector delta {};

	delta.x = destination.x - source.x;
	delta.y = destination.y - source.y;
	delta.z = destination.z - source.z;

	return sqrtf(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
}

Cheat::SDK::Misc::Vector Math::calculateAngle(const Cheat::SDK::Misc::Vector& source, const Cheat::SDK::Misc::Vector& destination)
{
	Cheat::SDK::Misc::Vector angle {};

	angle.x = -atan2f(destination.x - source.x, destination.y - source.y) / Constant::pi * 180.0f + 180.0f;
	angle.y = asinf((destination.z - source.z) / Math::distance(source, destination)) * 180.0f / Constant::pi;
	angle.z = 0.0f;

	return angle;
}
