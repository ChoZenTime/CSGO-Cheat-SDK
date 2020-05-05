#include "Menu.hpp"
#include "../Cheat/Configuration.hpp"

void Cheat::Core::Menu::render()
{
	static std::int32_t screenWidth{}, screenHeight{};
	fgui::render.get_screen_size(screenWidth, screenHeight);

	ADD_WINDOW(container["#window"], Configuration::menuX, Configuration::menuY, "FAIL PRIVATE", Configuration::menuHeight, Configuration::menuWidth, Configuration::menuOpen, Configuration::menuFont, false);

	REGISTER_CURSOR(fgui::cursor_type::NONE, fgui::input_state::UNLOCKED);
	REGISTER_TAB(tabs["#tabPanel"], 6, 2, fgui::tab_layout::VERTICAL, Configuration::iconFont, container["#window"], -1);
	REGISTER_NOTIFICATIONS(screenWidth, 25, Configuration::menuFont);

	ADD_TAB(tabs["#tabPanel"], "AIMBOT");
	{
		ADD_GROUPBOX(container["#legitGroupBox"], 172, 14, "LEGIT", 244, 342, Configuration::menuFont, container["#window"], 0, false, false, false);
		ADD_CONTROLLER(container["#legitGroupBox"], tabs["#tabPanel"]);
		ADD_CHECKBOX(checkbox["#legitEnabledCheckbox"], 8, 14, "ENABLED", "vars.legit", Configuration::menuFont, container["#legitGroupBox"], 0);

		ADD_GROUPBOX(container["#rageGroupBox"], 434, 14, "RAGE", 244, 342, Configuration::menuFont, container["#window"], 0, false, false, false);
		ADD_CONTROLLER(container["#rageGroupBox"], tabs["#tabPanel"]);
		ADD_CHECKBOX(checkbox["#rageCheckBox"], 8, 14, "ENABLED", "vars.rage", Configuration::menuFont, container["#rageGroupBox"], 0);
	}
	
	ADD_TAB(tabs["#tabPanel"], "VISUALS");
	{
		ADD_GROUPBOX(container["#visualsGroupBox"], 172, 14, "PLAYERS", 244, 342, Configuration::menuFont, container["#window"], 1, false, false, false);
		ADD_CONTROLLER(container["#visualsGroupBox"], tabs["#tabPanel"]);
		ADD_CHECKBOX(checkbox["#visualsCheckbox"], 8, 14, "ENABLED", "vars.visuals", Configuration::menuFont, container["#visualsGroupBox"], 0);
		ADD_CHECKBOX(checkbox["#enemyCheckbox"], 8, 32, "ENEMY", "vars.enemy", Configuration::menuFont, container["#visualsGroupBox"], 0);
		ADD_CHECKBOX(checkbox["#teamCheckbox"], 8, 50, "TEAM", "vars.team", Configuration::menuFont, container["#visualsGroupBox"], 0);
		ADD_CHECKBOX(checkbox["#boxCheckbox"], 8, 68, "BOX", "vars.box", Configuration::menuFont, container["#visualsGroupBox"], 0);
		ADD_CHECKBOX(checkbox["#healthCheckbox"], 8, 86, "HEALTH", "vars.health", Configuration::menuFont, container["#visualsGroupBox"], 0);
		ADD_CHECKBOX(checkbox["#armorCheckbox"], 8, 104, "ARMOR", "vars.armor", Configuration::menuFont, container["#visualsGroupBox"], 0);
		ADD_CHECKBOX(checkbox["#nameCheckbox"], 8, 122, "NAME", "vars.name", Configuration::menuFont, container["#visualsGroupBox"], 0);
		ADD_CHECKBOX(checkbox["#wallsCheckbox"], 8, 140, "THROUGH WALLS", "vars.walls", Configuration::menuFont, container["#visualsGroupBox"], 0);
		
		ADD_GROUPBOX(container["#worldGroupBox"], 434, 14, "WORLD", 244, 342, Configuration::menuFont, container["#window"], 1, false, false, false);
		ADD_CONTROLLER(container["#worldGroupBox"], tabs["#tabPanel"]);
		ADD_CHECKBOX(checkbox["#watermarkCheckBox"], 8, 14, "WATERMARK", "vars.watermark", Configuration::menuFont, container["#worldGroupBox"], 0);
	}

	ADD_TAB(tabs["#tabPanel"], "MISC");
	{
        ADD_GROUPBOX(container["#miscGroupBox"], 172, 14, "MISC", 244, 342, Configuration::menuFont, container["#window"], 2, false, false, false);
		ADD_CONTROLLER(container["#miscGroupBox"], tabs["#tabPanel"]);
		ADD_CHECKBOX(checkbox["#noNameCheckBox"], 8, 14, "NO NAME", "vars.noName", Configuration::menuFont, container["#miscGroupBox"], 0)
		ADD_CHECKBOX(checkbox["#bunnyHopCheckBox"], 8, 32, "BUNNY HOP", "vars.bunnyHop", Configuration::menuFont, container["#miscGroupBox"], 0);
		ADD_CHECKBOX(checkbox["#viewmodelFovCheckBox"], 8, 50, "VIEWMODEL", "vars.viewmodelFov", Configuration::menuFont, container["#miscGroupBox"], 0);
		ADD_SLIDER(slider["#viewmodelFovSlider"], 8, 70, " ", 0.0f, 0.0f, 68.0f, "vars.viewmodelFovSlider", Configuration::menuFont, container["#miscGroupBox"], 0);
		ADD_CHECKBOX(checkbox["#farViewmodelFovCheckBox"], 8, 88, "VIEWMODEL", "vars.farViewmodelFov", Configuration::menuFont, container["#miscGroupBox"], 0);
		ADD_SLIDER(slider["#farViewmodelFovSlider"], 8, 108, " ", 0.0f, 0.0f, 68.0f, "vars.farViewmodelFovSlider", Configuration::menuFont, container["#miscGroupBox"], 0);
	}
}