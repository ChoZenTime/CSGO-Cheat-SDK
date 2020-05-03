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

	constexpr std::string_view watermarkFont = "Korean";
	constexpr std::uint32_t    watermarkSize = 12;
	const     fgui::color      watermarkColor = { 250, 250, 250 };

	constexpr std::string_view visualsFont = "Korean";
	constexpr std::uint32_t    visualsSize = 12;

	const fgui::element_font menuFont = {"Japanese", 10, fgui::external::font_flags::ANTIALIAS, false};
	const fgui::element_font iconFont = {"Icon_Font", 50, fgui::external::font_flags::ANTIALIAS, false};
}
