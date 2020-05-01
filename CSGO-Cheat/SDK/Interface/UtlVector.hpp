#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/tier1/utlvector.h

namespace Cheat::SDK::Interface
{
	template <typename T> struct UtlVector
	{
		T& operator[](std::int32_t index)
		{
			return memory[index];
		}

		T* memory;

		std::int32_t allocationCount;
		std::int32_t growSize;
		std::int32_t size;

		T* elements;
	};
}
