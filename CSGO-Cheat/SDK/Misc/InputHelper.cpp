#include "InputHelper.hpp"
#include "../../Cheat/Interfaces.hpp"

namespace Cheat::SDK::Misc
{
	fgui::state getKeyState(const fgui::key& key)
	{
		return Core::Interface::getInterfaces.inputSystem->isButtonDown(key);
	}

	fgui::delta getScrollDelta()
	{
		return Core::Interface::getInterfaces.inputSystem->getAnalogDelta(Enum::AnalogCode::MouseWheel);
	}

	fgui::point getMousePosition()
	{
		static fgui::point point = {0, 0};

		Core::Interface::getInterfaces.surface->getCursorPosition(point.x, point.y);

		return point;
	}

	void setupInputFunctions()
	{
		fgui::input.get_key_state = getKeyState;
		fgui::input.get_scroll_delta = getScrollDelta;
		fgui::input.get_mouse_position = getMousePosition;
	}
}