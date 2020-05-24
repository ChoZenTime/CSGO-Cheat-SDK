#pragma once

#include "../../Cheat/Interfaces.hpp"
#include "../SDK/SDK.hpp"

#include <Windows.h>
#include <cstdint>

namespace Cheat::Core::Memory
{
	bool valid(std::uintptr_t);
	bool edit(void* memory, void* source, DWORD length);
	void patch(BYTE* destination, BYTE* source, std::uint16_t length);
	std::uintptr_t findPattern(const std::wstring_view moduleName, const BYTE* mask, const char* maskString);

	inline struct Memory
	{
		MEMORY_POINTER(clientMode, SDK::Interface::ClientMode, Interface::getInterfaces.baseClient, 10, 5);
		MEMORY_POINTER(globalVariables, SDK::Interface::GlobalVariables, Interface::getInterfaces.baseClient, 11, 10);
		MEMORY_POINTER(input, SDK::Interface::Input, Interface::getInterfaces.baseClient, 16, 1);
	}getMemory;
}