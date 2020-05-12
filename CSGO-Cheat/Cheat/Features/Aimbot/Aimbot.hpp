#pragma once

#include "../../../SDK/Interface/Entity.hpp"
#include "../../../SDK/Interface/UserCmd.hpp"

namespace Aimbot
{
	void rage(Cheat::SDK::Interface::UserCmd* cmd);
	Cheat::SDK::Interface::Entity* target();
}
