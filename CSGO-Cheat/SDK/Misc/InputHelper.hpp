#pragma once

#include "../../Dependencies/Gui/FGUI.hh"

namespace Cheat::SDK::Misc
{
	extern fgui::state getKeyState(const fgui::key&);
	extern fgui::delta getScrollDelta();
	extern fgui::point getMousePosition();
	extern void setupInputFunctions();
}