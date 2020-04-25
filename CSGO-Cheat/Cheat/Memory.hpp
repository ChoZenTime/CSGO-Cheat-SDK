#pragma once

#include <Windows.h>
#include <cstdint>

namespace Memory
{
	bool valid(std::uintptr_t);
	bool edit(void* memory, void* source, DWORD length);
	void patch(BYTE* destination, BYTE* source, std::uint16_t length);
}