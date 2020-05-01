#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/materialsystem/imaterial.h

#include "../Misc/Macros.hpp"

namespace Cheat::SDK::Interface
{
	struct Material
	{
		VFUNC(setAlpha(const float alpha), 27, void(__thiscall*)(void*, float), alpha);
		VFUNC(setColor(const float r, const float g, const float b), 28, void(__thiscall*)(void*, float, float, float), r, g, b);
		VFUNC(setFlag(const std::int32_t flag, const bool on), 29, void(__thiscall*)(void*, std::int32_t, bool), flag, on);
	};
}
