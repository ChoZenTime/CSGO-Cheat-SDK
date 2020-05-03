#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/vgui/IPanel.h

#include "../Misc/Macros.hpp"

namespace Cheat::SDK::Interface
{
	struct Panel
	{
		VFUNC(getPanelName(const std::uint32_t panelName), 36, const char* (__thiscall*)(void*, std::uint32_t), panelName)
		VFUNC(getClassName(const std::uint32_t className), 37, const char* (__thiscall*)(void*, std::uint32_t), className)
	};
}