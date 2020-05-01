#pragma once

namespace Cheat::SDK::Misc
{
	template <typename T> static T vfuncFromIndex(void* base, const std::uint32_t index)
	{
		return (*static_cast<T**>(base))[index];
	}
}
