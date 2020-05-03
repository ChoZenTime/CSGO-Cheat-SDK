#include "Menu.hpp"
#include "../Cheat/Configuration.hpp"

void Cheat::Core::Menu::render()
{
		static std::int32_t screenWidth {}, screenHeight {};
		fgui::render.get_screen_size(screenWidth, screenHeight);
	
		ADD_WINDOW(container["#window"], Configuration::menuX, Configuration::menuY, "FAIL PRIVATE", Configuration::menuHeight, Configuration::menuWidth, Configuration::menuOpen, Configuration::menuFont, false);
	
		REGISTER_CURSOR(fgui::cursor_type::NONE , fgui::input_state::UNLOCKED);
		REGISTER_TAB(tabs["#tabPanel"], 6, 2, fgui::tab_layout::VERTICAL, Configuration::iconFont, container["#window"], -1);
		REGISTER_NOTIFICATIONS(screenWidth, 25, Configuration::menuFont);
	
		ADD_TAB(tabs["#tabPanel"], "a");
		{
			ADD_GROUPBOX(container["#playersGroupBox"], 180, 14, "PLAYERS", 240, 342, Configuration::menuFont, container["#window"], 0, false, false, false);
			ADD_CONTROLLER(container["#playersGroupBox"], tabs["#tabPanel"]);
			ADD_CHECKBOX(checkBox["#playerVisualsEnabledCheckbox"], 8, 14, "ENABLED", "vars.playerVisuals", Configuration::menuFont, container["#playersGroupBox"], 0);

			ADD_GROUPBOX(container["#worldGroupBox"], 440, 14, "WORLD", 240, 342, Configuration::menuFont, container["#window"], 0, false, false, false);
			ADD_CONTROLLER(container["#worldGroupBox"], tabs["#tabPanel"]);
			ADD_CHECKBOX(checkBox["#watermarkCheckBox"], 8, 14, "WATERMARK", "vars.watermark", Configuration::menuFont, container["#worldGroupBox"], 0);
		}
	
		ADD_TAB(tabs["#tabPanel"], "b");
		{

		}
	
		ADD_TAB(tabs["#tabPanel"], "c");
		{

		}
}

