#pragma once

#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE module, DWORD callReason, LPVOID reserved);

namespace Debug
{
	void freeModule();
	void setDebugConsole();
	void printDebugInfo();
}