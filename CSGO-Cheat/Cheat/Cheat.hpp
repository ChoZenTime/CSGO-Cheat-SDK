#pragma once

#include <Windows.h>

namespace Cheat::Core
{
	extern void attach(const LPVOID *thread);
	extern void detach(const LPVOID* thread);
}