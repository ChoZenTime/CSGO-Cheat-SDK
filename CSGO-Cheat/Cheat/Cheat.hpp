#pragma once

#include <Windows.h>

namespace Cheat::Core
{
	extern DWORD WINAPI attach(LPVOID thread);
	extern BOOL  WINAPI detach();
}