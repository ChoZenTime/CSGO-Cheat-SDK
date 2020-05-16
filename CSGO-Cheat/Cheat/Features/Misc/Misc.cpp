#include "Misc.hpp"
#include "../../Interfaces.hpp"
#include "../../../Menu/Menu.hpp"
#include "../../../SDK/SDK.hpp"
#include "../../../SDK/Misc/Vector.hpp"

void Misc::bunnyHop(Cheat::SDK::Interface::UserCmd* cmd)
{
	if (!Cheat::Core::Menu::checkbox["#bunnyHopCheckBox"]->get_bool()) return;

	if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Move::Ladder)) return;
	
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
	auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());
	if (!localPlayer) return;
	
	if (Cheat::Core::Menu::checkbox["#noFlashCheckBox"]->get_bool())
	{
		localPlayer->flashAlpha() = 0.0f;
	}
	else
	{
		localPlayer->flashAlpha() = 255.0f;

	}
}

void Misc::showRank()
{
	if (!Cheat::Core::Menu::checkbox["#showRanksCheckBox"]->get_bool()) return;

	Cheat::Core::Interface::getInterfaces.baseClient->dispatchUserMessage(50, 0, 0, nullptr);
}

void Misc::autoStrafe(Cheat::SDK::Interface::UserCmd* cmd)
{
	if (!Cheat::Core::Menu::checkbox["#autoStrafeCheckBox"]->get_bool()) return;

	auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

	if (!localPlayer) return;
	if (!localPlayer->health() > 0) return;

	if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Move::Ladder)) return;
	if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Move::NoClip)) return;

	if (localPlayer->flags() & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Flags::OnGround)) return;

	cmd->sideMove = cmd->mouseX < 0.f ? -450.f : 450.f;
}

void Misc::edgeJump(Cheat::SDK::Interface::UserCmd* cmd)
{
	if (!Cheat::Core::Menu::checkbox["#edgeJumpCheckBox"]->get_bool()) return;

	if (!Cheat::Core::Interface::getInterfaces.inputSystem->isButtonDown(Configuration::edgeJumpKey)) return;

	auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

	if (!localPlayer) return;
	if (!localPlayer->health() > 0) return;

	if (!(localPlayer->flags() & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Flags::OnGround)))
	{
		cmd->buttons |= CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::Jump);
	}
}

void Misc::noDuckCooldown(Cheat::SDK::Interface::UserCmd* cmd)
{
	if (!Cheat::Core::Menu::checkbox["#noDuckCooldownCheckBox"]->get_bool()) return;

	auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

	if (!localPlayer) return;
	if (!localPlayer->health() > 0) return;

	cmd->buttons |= CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::BullRush);
}

void Misc::disablePostProcessing()
{
	auto* postProcessing = Cheat::Core::Interface::getInterfaces.cvar->findCvar("mat_postprocess_enable");
	
	if (Cheat::Core::Menu::checkbox["#disablePostProcessingCheckBox"]->get_bool())
	{
		postProcessing->setValue(0);
	}
	else
	{
		postProcessing->setValue(1);
	}
}

void Misc::grayMap()
{
	auto* grayMap = Cheat::Core::Interface::getInterfaces.cvar->findCvar("mat_drawgray");
	
	if (Cheat::Core::Menu::checkbox["#grayMapCheckBox"]->get_bool())
	{
		grayMap->setValue(1);
	}
	else
	{
		grayMap->setValue(0);
	}
}

void Misc::tazerEffect()
{
	auto* tazerEffect = Cheat::Core::Interface::getInterfaces.cvar->findCvar("sv_party_mode");

	if (Cheat::Core::Menu::checkbox["#tazerEffectCheckBox"]->get_bool())
	{
		tazerEffect->setValue(1);
	}
	else
	{
		tazerEffect->setValue(0);
	}
}

void Misc::moonWalk(Cheat::SDK::Interface::UserCmd* cmd)
{
	if (!Cheat::Core::Menu::checkbox["#moonWalkCheckBox"]->get_bool()) return;

	auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());
	if (!(localPlayer->flags() & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Flags::OnGround))) return;

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
		cmd->forwardMove = -450;
		cmd->buttons &= ~CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::MoveLeft);
		cmd->buttons |= CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::MoveRight);
	}
	else if (cmd->buttons & CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::MoveRight))
	{
		cmd->forwardMove = 450;
		cmd->buttons &= ~CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::MoveRight);
		cmd->buttons |= CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Button::MoveLeft);
	}
}