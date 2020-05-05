#include "Visuals.hpp"
#include "../../Interfaces.hpp"
#include "../../Memory.hpp"
#include "../../../Dependencies/Fmt/core.hh"
#include "../../../SDK/Interface/ViewSetup.hpp"
#include "../../Cheat/Configuration.hpp"
#include "../../Menu/Menu.hpp"
#include "../../SDK/SDK.hpp"

void Visuals::renderWindow()
{
	Cheat::Core::Interface::getInterfaces.surface->clippingEnabled() = true;

	fgui::handler::render_window();

	Cheat::Core::Interface::getInterfaces.surface->clippingEnabled() = false;
}

void Visuals::watermark()
{
	if (!Cheat::Core::Menu::checkbox["#watermarkCheckBox"]->get_bool()) return;

	Cheat::SDK::Misc::text(5, 5, Configuration::watermarkColor, Cheat::SDK::Misc::fonts[CONVERT_ENUM_TYPE(std::uint32_t, Cheat::SDK::Enum::Font::Watermark)], "FAIL PRIVATE 0.1");
}

void Visuals::viewmodel(Cheat::SDK::Interface::ViewSetup* viewSetup)
{
	auto *localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

	if (!localPlayer) return;
	
	viewSetup->viewModelFov += Cheat::Core::Menu::checkbox["#viewmodelFovCheckBox"]->get_bool() && !localPlayer->scoped() ? Cheat::Core::Menu::slider["#viewmodelFovSlider"]->get_value() : 0.0f;
}

void Visuals::farViewmodel(Cheat::SDK::Interface::ViewSetup* viewSetup)
{
	auto *localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

	if (!localPlayer) return;

	viewSetup->farViewModel += Cheat::Core::Menu::checkbox["#farViewmodelFovCheckBox"]->get_bool() && !localPlayer->scoped() ? Cheat::Core::Menu::slider["#viewmodelFovSlider"]->get_value() : 0.0f;
}

void Visuals::grenadePreview()
{	
	static auto* grenadePreview = Cheat::Core::Interface::getInterfaces.cvar->findCvar("cl_grenadepreview");
	static auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

	if (!grenadePreview || localPlayer) return;

	if (!(localPlayer->health() > 0)) return;

	grenadePreview->setValue(Cheat::Core::Menu::checkbox["#grenadePreviewCheckBox"]->get_bool() ? 1 : 0);
}

void Visuals::esp()
{
	if (!Cheat::Core::Menu::checkbox["#visualsCheckbox"]->get_bool()) return;

	auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());
	
	if (!localPlayer) return;

	for (auto index = 1; index <= Cheat::Core::Memory::getMemory.globalVariables->maxClients; index++)
	{
		auto* entity = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(index);

		if (!entity) continue;

		if (!(entity->health() > 0)) continue;

		if (entity == localPlayer) continue;
		
		static Cheat::SDK::Interface::PlayerInfo playerInfo {};

		static Cheat::SDK::Misc::Vector screen{};

		if (!Cheat::Core::Interface::getInterfaces.engine->getPlayerInfo(index, playerInfo)) continue;

		if (!(Cheat::Core::Interface::getInterfaces.debugOverlay->screenPosition(entity->vecOrigin(), screen) != 1)) continue;
		
		//TODO: Add dormant
		if (Cheat::Core::Menu::checkbox["#enemyCheckbox"]->get_bool())
		{
			if (localPlayer->team() != entity->team())
			{
				if (Cheat::Core::Menu::checkbox["#boxCheckbox"]->get_bool())
				{

				}
				
				if (Cheat::Core::Menu::checkbox["#nameCheckbox"]->get_bool())
				{
					//Cheat::SDK::Misc::text(screen.x, screen.y, Configuration::nameColor, Cheat::SDK::Misc::fonts[(CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Font::Visuals))], playerInfo.name);
				}

				if (Cheat::Core::Menu::checkbox["#armorCheckbox"]->get_bool())
				{
					//Cheat::SDK::Misc::text(screen.x, screen.y + 30, Configuration::armorColor, Cheat::SDK::Misc::fonts[(CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Font::Visuals))], fmt::format("ARMOR: {:d}", entity->armorValue()));
				}

				if (Cheat::Core::Menu::checkbox["#healthCheckbox"]->get_bool())
				{
					//Cheat::SDK::Misc::text(screen.x, screen.y + 15, Configuration::healthColor, Cheat::SDK::Misc::fonts[(CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Font::Visuals))], fmt::format("HEALTH: {:d}", entity->health()));
				}
			}
		}
		
		if (Cheat::Core::Menu::checkbox["#teamCheckbox"]->get_bool())
		{
			if (localPlayer->team() == entity->team())
			{
				if (Cheat::Core::Menu::checkbox["#boxCheckbox"]->get_bool())
				{

				}
				
				if (Cheat::Core::Menu::checkbox["#healthCheckbox"]->get_bool())
				{
					//Cheat::SDK::Misc::text(screen.x, screen.y + 15, Configuration::healthColor, Cheat::SDK::Misc::fonts[(CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Font::Visuals))], fmt::format("HEALTH: {:d}", entity->health()));	
				}
				
				if (Cheat::Core::Menu::checkbox["#armorCheckbox"]->get_bool())
				{
					//Cheat::SDK::Misc::text(screen.x, screen.y + 30, Configuration::armorColor, Cheat::SDK::Misc::fonts[(CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Font::Visuals))], fmt::format("ARMOR: {:d}", entity->armorValue()));	
				}
				
				if (Cheat::Core::Menu::checkbox["#nameCheckbox"]->get_bool())
				{
					//Cheat::SDK::Misc::text(screen.x, screen.y, Configuration::nameColor, Cheat::SDK::Misc::fonts[(CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Font::Visuals))], playerInfo.name);
				}
			}			
		}

		
	}

}