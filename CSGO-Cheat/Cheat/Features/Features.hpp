#pragma once

#include "../../SDK/SDK.hpp"

namespace Cheat::Core::Features
{
	inline void window()
	{
		Interface::getInterfaces.surface->clippingEnabled() = true;

		fgui::handler::render_window();

		Interface::getInterfaces.surface->clippingEnabled() = false;
	}
}