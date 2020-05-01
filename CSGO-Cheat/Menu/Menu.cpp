#include "Menu.hpp"
#include "../Cheat/Configuration.hpp"

void Cheat::Core::Menu::render()
{
		static std::int32_t screenWidth {}, screenHeight {};
		fgui::render.get_screen_size(screenWidth, screenHeight);
		
		ADD_WINDOW(container["#window"], Configuration::menuHeight, Configuration::menuWidth, Configuration::cheatName, 718, 454, Configuration::menuOpen, Configuration::menuFont, false);
		
		REGISTER_CURSOR(fgui::cursor_type::ARROW, fgui::input_state::UNLOCKED);
		REGISTER_TAB(tabs["#tabPanel"], 6, 2, fgui::tab_layout::VERTICAL, Configuration::iconFont, container["#window"], -1);

		// TODO: Fix this
		const fgui::element_font menu = { "Tahoma", 12, fgui::external::font_flags::SHADOW, false };
		REGISTER_NOTIFICATIONS(screenWidth, 25, menu);

		ADD_TAB(tabs["#tabPanel"], "test");
		{
			
		}
}


