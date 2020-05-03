#include "Menu.hpp"
#include "../Cheat/Configuration.hpp"

void Cheat::Core::Menu::render()
{
		static std::int32_t screenWidth {}, screenHeight {};
		fgui::render.get_screen_size(screenWidth, screenHeight);

		ADD_WINDOW(container["#window"], Configuration::menuX, Configuration::menuY, "fail", Configuration::menuHeight, Configuration::menuWidth, fgui::external::KEY_PAGEUP, Configuration::menuFont, false);
	
		REGISTER_CURSOR(fgui::cursor_type::NONE , fgui::input_state::UNLOCKED);
		REGISTER_TAB(tabs["#tabPanel"], 6, 2, fgui::tab_layout::VERTICAL, Configuration::iconFont, container["#window"], -1);
		REGISTER_NOTIFICATIONS(screenWidth, 25, Configuration::menuFont);
	
		ADD_TAB(tabs["#tabPanel"], "a");
		{
			
		}
	
		ADD_TAB(tabs["#tabPanel"], "b");
		{

		}
	
		ADD_TAB(tabs["#tabPanel"], "c");
		{

		}
}

