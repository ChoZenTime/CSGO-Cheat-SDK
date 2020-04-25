#pragma once

#include <Windows.h>
#include <cstdint>
#include <string>

namespace Injector
{
	BOOL main();
	void detach(HANDLE process, LPVOID path, HANDLE thread);
	std::uint32_t findProcess(std::string_view processName);
}
