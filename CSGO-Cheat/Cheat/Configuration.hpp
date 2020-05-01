#pragma once

namespace Configuration
{
	constexpr auto menuOpen      = VK_PRIOR; // Page up
	constexpr auto exitThreadKey = VK_NEXT;  // Page dow

	constexpr auto menuHeight = 200;
	constexpr auto menuWidth  = 200;

	constexpr std::string        cheatName = "test";

	constexpr std::string_view   menuFont = "Tahoma";
	constexpr std::uint32_t      menuSize = 12;

	constexpr std::string_view  watermarkFont = "Tahoma";
	constexpr std::uint32_t     watermarkSize = 12;

	constexpr std::string_view  visualsFont = "Tahoma";
	constexpr std::uint32_t     visualsSize = 12;

	constexpr std::string_view  iconFont = "Tahoma";
	constexpr std::uint32_t     iconSize = 12;
}
