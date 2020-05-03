#pragma once

#include <Windows.h>

namespace Cheat::Core
{
	extern void attach(HMODULE module);
	extern void detach(HMODULE module);
}