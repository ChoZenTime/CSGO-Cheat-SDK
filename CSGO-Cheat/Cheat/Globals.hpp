#pragma once
#include "Structures/Entity.hpp"

namespace Globals
{
	bool initializeGameGlobals();
	bool initializeMatchGlobals();

	extern Cheat::Structures::EntityList* entityList;
}
