#pragma once

#include <Windows.h>
#include <cstdint>

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/tier1/interface.cpp

namespace Cheat::SDK::Misc
{
	template < typename T > static T captureInterface(const char* moduleName, const char* interfaceName)
	{
		const auto moduleHandle = GetModuleHandleA(moduleName);

		if (!moduleHandle) return {};

		const auto createInterface = reinterpret_cast<T(__cdecl*)(const char*, std::int32_t*)>(GetProcAddress(moduleHandle, "CreateInterface"));

		if (!createInterface) return {};

		return createInterface(interfaceName, nullptr);
	}
}