#pragma once

#include "../Menu/Menu.hpp"

#include <cstdint>
#include <string>

namespace Configuration
{
	constexpr auto menuOpen = fgui::external::KEY_PAGEUP;
	constexpr auto exitThreadKey = VK_NEXT;  // Page down

	constexpr auto menuHeight = 700;
	constexpr auto menuWidth  = 400;

	constexpr auto menuX = 200;
	constexpr auto menuY = 200;

	constexpr std::string_view watermarkFont = "Japanese";
	constexpr std::uint32_t    watermarkSize = 10;
	const     fgui::color      watermarkColor = { 250, 250, 250 };

	constexpr std::string_view visualsFont = "Japanese";
	constexpr std::uint32_t    visualsSize = 10;

	const fgui::element_font menuFont = {"Japanese", 10, fgui::external::font_flags::ANTIALIAS, false};
	const fgui::element_font iconFont = {"Japanese", 12, fgui::external::font_flags::ANTIALIAS, false};

	const fgui::color nameColor   = {255, 255, 255};
	const fgui::color healthColor = {255, 255, 255};
	const fgui::color boxColor    = {255, 255, 255};
	const fgui::color armorColor  = {255, 255, 255};
}
