#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/mathlib/vector.h

#include <cmath>

namespace Cheat::SDK::Misc
{
	struct Vector
	{
		float x, y, z;

		explicit Vector(const float w = 0, const float h = 0, const float r = 0)
		{
			x = w;
			y = h;
			z = r;
		}

		Vector operator+(const Vector& point) const
		{
			return Vector(x + point.x, y + point.y, z + point.z);
		}

		Vector operator-(const Vector& point) const
		{
			return Vector(x - point.x, y - point.y, z - point.z);
		}

		Vector operator*(const float point) const
		{
			return Vector(x * point, y * point, z * point);
		}

		Vector& operator=(const float array[3])
		{
			x = array[0];
			y = array[1];
			z = array[2];

			return *this;
		}

		Vector& operator+=(const Vector& point)
		{
			x += point.x;
			y += point.y;
			z += point.z;

			return *this;
		}

		Vector& operator-=(const Vector& point)
		{
			x -= point.x;
			y -= point.y;
			z -= point.z;

			return *this;
		}

		Vector& operator/=(const float division)
		{
			x /= division;
			y /= division;
			z /= division;

			return *this;
		}

		[[nodiscard]] auto length() const
		{
			return std::sqrtf(x * x + y * y + z * z);
		}

		void normalize()
		{
			x = std::isfinite(x) ? std::remainderf(x, 360.0f) : 0.0f;
			y = std::isfinite(y) ? std::remainderf(y, 360.0f) : 0.0f;
			z = 0.0f;
		}
	};
}
