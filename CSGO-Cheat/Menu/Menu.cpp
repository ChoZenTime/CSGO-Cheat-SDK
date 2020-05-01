#include "Menu.hpp"
#include "../Cheat/Configuration.hpp"

namespace Cheat::Core::Menu
{
	void render()
	{
		static std::int32_t screenWidth {}, screenHeight {};
		fgui::render.get_screen_size(screenWidth, screenHeight);
		
		ADD_WINDOW(container["#window"], 200, 200, Configuration::cheatName, 718, 454, Configuration::menuOpen, Configuration::menuFont, false);
		
		REGISTER_CURSOR(fgui::cursor_type::ARROW, fgui::input_state::UNLOCKED);
		REGISTER_TAB(tabs["#tabPanel"], 6, 2, fgui::tab_layout::VERTICAL, Configuration::iconFont, container["#window"], -1);
		REGISTER_NOTIFICATIONS(screenWidth, 25,Configuration::menuFont);

		ADD_TAB(tabs["#tabPanel"], "test");
		{
			
		}
	}
}
