#pragma once

namespace Configuration
{
	constexpr auto menuOpen      = VK_PRIOR; // Page up
	constexpr auto exitThreadKey = VK_NEXT;  // Page dow

	constexpr std::string cheatName = "test";

	const fgui::element_font menuFont      = { "Tahoma", 12, fgui::external::font_flags::SHADOW, false };
	const fgui::element_font iconFont      = { "Tahoma", 12, fgui::external::font_flags::SHADOW, false };
	const fgui::element_font watermarkFont = { "Tahoma", 12, fgui::external::font_flags::SHADOW, false };
	const fgui::element_font visualsFont   = { "Tahoma", 12, fgui::external::font_flags::SHADOW, false };
}
