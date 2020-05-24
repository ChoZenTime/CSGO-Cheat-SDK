#include "Visuals.hpp"
#include "../../Interfaces.hpp"
#include "../../../Memory/Memory.hpp"
#include "../../../SDK/Interface/ViewSetup.hpp"
#include "../../../SDK/Misc/Vector.hpp"
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

		Cheat::SDK::Interface::PlayerInfo playerInfo {};
		Cheat::SDK::Misc::Vector screen {};

		if (!Cheat::Core::Interface::getInterfaces.engine->getPlayerInfo(index, playerInfo)) continue;

		if (!(Cheat::Core::Interface::getInterfaces.debugOverlay->screenPosition(entity->vecOrigin(), screen) != 1)) continue;
		
		//TODO: Add dormant
		if (Cheat::Core::Menu::checkbox["#enemyCheckbox"]->get_bool())
		{
			if (localPlayer->team() != entity->team())
			{
				if (Cheat::Core::Menu::checkbox["#boxCheckbox"]->get_bool())
				{
					// TODO: Need world to screen function
					Cheat::SDK::Misc::outlinedRectangle(screen.x, screen.y - 50, 25, 50, Configuration::boxColor);
				}
				
				if (Cheat::Core::Menu::checkbox["#nameCheckbox"]->get_bool())
				{
					Cheat::SDK::Misc::text(screen.x, screen.y, Configuration::nameColor, Cheat::SDK::Misc::fonts[CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Font::Visuals)], playerInfo.name);
				}

				if (Cheat::Core::Menu::checkbox["#armorCheckbox"]->get_bool())
				{

				}

				if (Cheat::Core::Menu::checkbox["#healthCheckbox"]->get_bool())
				{

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

				}
				
				if (Cheat::Core::Menu::checkbox["#armorCheckbox"]->get_bool())
				{

				}
				
				if (Cheat::Core::Menu::checkbox["#nameCheckbox"]->get_bool())
				{
					Cheat::SDK::Misc::text(screen.x, screen.y, Configuration::nameColor, Cheat::SDK::Misc::fonts[(CONVERT_ENUM_TYPE(std::int32_t, Cheat::SDK::Enum::Font::Visuals))], playerInfo.name);
				}
			}			
		}
	}
}

void Visuals::sniperCrosshair()
{
	// TODO: Add sniper weapon checks
	// Make a better crosshair
	if (!Cheat::Core::Menu::checkbox["#sniperCrosshairCheckBox"]->get_bool()) return;

	std::int32_t screenWidth{}, screenHeight{};
	fgui::render.get_screen_size(screenWidth, screenHeight);

	const auto radius  = Configuration::crosshairRadius;
	const auto segment = Configuration::crosshairSegment;

	auto* crosshair = Cheat::Core::Interface::getInterfaces.cvar->findCvar("crosshair");
	crosshair->setValue(0);
	
	Cheat::SDK::Misc::circle(screenWidth / 2, screenHeight / 2, radius, segment, Configuration::crosshairColor);
}

void Visuals::viewmodelFov(Cheat::SDK::Interface::ViewSetup* viewSetup)
{
	if (!Cheat::Core::Menu::checkbox["#viewmodelFovCheckBox"]->get_bool()) return;
	
	auto* viewmodelFov = Cheat::Core::Interface::getInterfaces.cvar->findCvar("viewmodel_fov");
	
	auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

	if (!viewmodelFov || localPlayer) return;
	if (!(localPlayer->health() > 0)) return;

	viewmodelFov->setValue(!localPlayer->scoped() ? Cheat::Core::Menu::slider["#viewmodelFovSlider"]->get_value() : 0.0f);
}

void Visuals::grenadePreview()
{
	// Fix
	auto* grenadePreview = Cheat::Core::Interface::getInterfaces.cvar->findCvar("cl_grenadepreview");
	auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

	if (!grenadePreview || localPlayer) return;
	if (!(localPlayer->health() > 0)) return;

	grenadePreview->setValue(Cheat::Core::Menu::checkbox["#grenadePreviewCheckBox"]->get_bool() ? 1 : 0);
}

void Visuals::skyChanger()
{
	if (!Cheat::Core::Menu::checkbox["#skyChangerCheckBox"]->get_bool()) return;

	// Add
}

