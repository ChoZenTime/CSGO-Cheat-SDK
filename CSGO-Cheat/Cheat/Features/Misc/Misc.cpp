#include "Misc.hpp"
#include "../../Interfaces.hpp"
#include "../../../Menu/Menu.hpp"
#include "../../../SDK/SDK.hpp"

void Misc::bunnyHop(Cheat::SDK::Interface::UserCmd* cmd)
{
	if (!Cheat::Core::Menu::checkbox["#bunnyHopCheckBox"]->get_bool()) return;

   auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

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

void Misc::noFlash()
{
	if (!Cheat::Core::Menu::checkbox["#noFlashCheckBox"]->get_bool()) return;

	auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

	if (!localPlayer) return;

	localPlayer->flashAlpha() = 0.0f;
}

void Misc::showRank()
{
	if (!Cheat::Core::Menu::checkbox["#showRanksCheckBox"]->get_bool()) return;

	Cheat::Core::Interface::getInterfaces.baseClient->dispatchUserMessage(50, 0, 0, nullptr);

}

void Misc::autoStrafe(Cheat::SDK::Interface::UserCmd* cmd)
{
	if (!Cheat::Core::Menu::checkbox["#autoStrafeCheckBox"]->get_bool()) return;

	bool backward {};

	if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Forward))
	{
		backward = false;
	}
	else if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Back))
	{
		backward = true;
	}

	auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

	if (!localPlayer) return;
	if (!localPlayer->health() > 0) return;

	if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Forward)) return;
	if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Back))    return;
	if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Left))    return;
	if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Right))   return;

	if (cmd->mouseX <= 1 && cmd->mouseX >= -1) return;

	if (localPlayer->flags() & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Flags::OnGround)) return;

	if (backward)
	{
		cmd->sideMove = cmd->mouseX < 0.f ? 450.f : -450.f;
	}
	else
	{
		cmd->sideMove = cmd->mouseX < 0.f ? -450.0f : 450.0f;
	}
}

void Misc::moonWalk(Cheat::SDK::Interface::UserCmd* cmd)
{
	if (!Cheat::Core::Menu::checkbox["#moonWalkCheckBox"]->get_bool()) return;

	auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

	if (!(localPlayer->flags() & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Flags::OnGround))) return;
	if (localPlayer->flags() & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Flags::OnTrain)) return;

	if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Forward))
	{
		cmd->forwardMove = 450;
		cmd->buttons &= ~CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Forward);
		cmd->buttons |= CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Back);
	}
	else if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Back))
	{
		cmd->forwardMove = -450;
		cmd->buttons &= ~CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Back);
		cmd->buttons |= CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Forward);
	}

	if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::MoveLeft))
	{
		cmd->sideMove = -450;
		cmd->buttons &= ~CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::MoveLeft);
		cmd->buttons |= CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::MoveRight);
	}
	if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::MoveRight))
	{
		cmd->sideMove = 450;
		cmd->buttons &= ~CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::MoveRight);
		cmd->buttons |= CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::MoveLeft);
	}
}