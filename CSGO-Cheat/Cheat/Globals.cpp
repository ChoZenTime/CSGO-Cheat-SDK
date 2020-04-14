#include "Globals.hpp"

#include "Configuration.hpp"
#include "Structures/Entity.hpp"

#include <cstdint>
#include <cstddef>
#include <cstdio>

#include <Windows.h>

using namespace Cheat::Structures;

namespace Globals
{	
	namespace Offsets
	{
		constexpr std::ptrdiff_t dwEntityList = 0x4D42A34;
		constexpr std::ptrdiff_t dwViewMatrix = 0x4D34374;
	}
	
	std::uintptr_t clientModule{};
	std::uintptr_t engineModule{};

	EntityList* entityList{};
}

bool Globals::initializeGameGlobals()
{
	clientModule = reinterpret_cast<std::uintptr_t>(GetModuleHandle(L"client_panorama.dll"));
	if (!clientModule)
	{
		if (Configuration::debugPrint)
			printf("[-] Failed to retrieve client_panorama.dll module\n");

		return false;
	}

	engineModule = reinterpret_cast<std::uintptr_t>(GetModuleHandle(L"engine.dll"));
	if (!engineModule)
	{
		if (Configuration::debugPrint)
			printf("[-] Failed to retrieve engine.dll module\n");

		return false;
	}

	return true;
}

bool Globals::initializeMatchGlobals()
{
	entityList = reinterpret_cast<EntityList*>(clientModule + Offsets::dwEntityList);
	if (!entityList)
	{
		if (Configuration::debugPrint)
			printf("[-] Failed to retrieve the entity list\n");

		return false;
	}
	
	return true;
}
