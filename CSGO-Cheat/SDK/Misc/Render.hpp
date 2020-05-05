#pragma once

#include "../../Dependencies/Gui/FGUI.hh"

#include <vector>

namespace Cheat::SDK::Misc
{
	inline std::vector<fgui::font> fonts;

	extern void createFont(fgui::font&, std::string_view, std::int32_t, std::int32_t, bool);
	extern void getScreenSize(std::int32_t&, std::int32_t&);
	extern fgui::dimension getTextSize(const fgui::font&, std::string_view);
	extern void rectangle(std::int32_t, std::int32_t, std::int32_t, std::int32_t, fgui::color);
	extern void outlinedRectangle(std::int32_t, std::int32_t, std::int32_t, std::int32_t, fgui::color);
	extern void line(std::int32_t, std::int32_t, std::int32_t, std::int32_t, fgui::color);
	extern void polygon(std::int32_t, fgui::vertex*, fgui::color);
	extern void text(std::int32_t, std::int32_t, fgui::color, unsigned long, std::string_view);
	extern void circle(std::int32_t, std::int32_t, std::int32_t, std::int32_t, fgui::color);
	extern void gradient(std::int32_t, std::int32_t, std::int32_t, std::int32_t, std::int32_t, std::int32_t, fgui::color, bool);
	extern void coloredGradient(std::int32_t, std::int32_t, std::int32_t, std::int32_t, fgui::color, fgui::color, bool);
	extern void getAlphaValue(std::int32_t, std::int32_t, std::int32_t, std::int32_t);
	extern void clipRectangle(std::int32_t, std::int32_t, std::int32_t, std::int32_t);

	extern void setupRenderFunctions();
}
