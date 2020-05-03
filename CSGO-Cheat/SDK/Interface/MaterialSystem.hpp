#pragma once

#include "Material.hpp"
#include "../Misc/Macros.hpp"

namespace Cheat::SDK::Interface
{
	struct MaterialSystem
	{
		VFUNC(findMaterial(const char* materialName), 84, Material* (__thiscall*)(void*, const char*), materialName)
	};
}