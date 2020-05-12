#include "AntiAim.hpp"
#include "../../Interfaces.hpp"
#include "../../../Menu/Menu.hpp"

// In progress
void AntiAim::legit(Cheat::SDK::Interface::UserCmd* cmd, bool& sendPacket)
{
	if (!Cheat::Core::Menu::checkbox["#legitAntiAimCheckBox"]->get_bool()) return;

	auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

	// TODO: Add grenade checks
	if (!localPlayer) return;
	if (!localPlayer->health() > 0) return;
	if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Move::Ladder)) return;
	if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Attack)) return;
	
	auto angle = cmd->viewAngles;
}
