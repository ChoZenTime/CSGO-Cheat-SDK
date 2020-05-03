#include "Visuals.hpp"

#include "../../../SDK/Interface/ViewSetup.hpp"

#include "../../Cheat/Configuration.hpp"
#include "../../Menu/Menu.hpp"
#include "../../SDK/SDK.hpp"

void Cheat::Core::Features::renderWindow()
{
	Interface::getInterfaces.surface->clippingEnabled() = true;

	fgui::handler::render_window();

	Interface::getInterfaces.surface->clippingEnabled() = false;
}

void Cheat::Core::Features::watermark()
{
	if (!Menu::checkBox["#watermarkCheckBox"]->get_bool()) return;

	SDK::Misc::text(5, 5, Configuration::watermarkColor, SDK::Misc::fonts[CONVERT_ENUM_TYPE(std::uint32_t, SDK::Enum::Font::Watermark)], "FAIL PRIVATE");
}

void Cheat::Core::Features::viewmodel(SDK::Interface::ViewSetup* viewSetup)
{
	static auto localPlayer = Interface::getInterfaces.clientEntity->getClientEntity(Interface::getInterfaces.engine->getLocalPlayer());

	if (!localPlayer) return;
	
	viewSetup->viewModelFov += Menu::checkBox["#viewmodelFovCheckbox"]->get_bool() && !localPlayer->isScoped() ? Menu::slider["#viewmodelFovSlider"]->get_value() : 0.0f;
}