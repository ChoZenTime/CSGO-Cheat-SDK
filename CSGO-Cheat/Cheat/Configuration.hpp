#pragma once

#include "../Menu/Menu.hpp"

#include <cstdint>
#include <string>

namespace Configuration
{
	constexpr auto menuOpen      = VK_PRIOR; // Page up
	constexpr auto exitThreadKey = VK_NEXT;  // Page down

	constexpr auto menuHeight = 700;
	constexpr auto menuWidth  = 400;

	constexpr auto menuX = 200;
	constexpr auto menuY = 200;

	constexpr std::string_view watermarkFont = "Tahoma";
	constexpr std::uint32_t    watermarkSize = 12;

	constexpr std::string_view visualsFont = "Tahoma";
	constexpr std::uint32_t    visualsSize = 12;

	const fgui::element_font menuFont = {"Tahoma", 12, fgui::external::font_flags::SHADOW, false};
	const fgui::element_font iconFont = {"Icon_Font", 50, fgui::external::font_flags::ANTIALIAS, false};
}
