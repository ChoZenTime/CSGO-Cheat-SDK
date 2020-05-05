#include "Misc.hpp"
#include "../../Interfaces.hpp"
#include "../../../Menu/Menu.hpp"
#include "../../../SDK/SDK.hpp"

void Misc::bunnyHop(Cheat::SDK::Interface::UserCmd* cmd)
{
	if (!Cheat::Core::Menu::checkbox["#bunnyHopCheckBox"]->get_bool()) return;

	static auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

	if (!localPlayer) return;

	if (!localPlayer->health() > 0) return;

	if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Jump))
	{
		if (!(localPlayer->flags() & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Flags::OnGround)))
		{
			cmd->buttons &= ~CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Jump);
		}
	}
}

