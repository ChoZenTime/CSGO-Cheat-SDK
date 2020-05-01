#pragma once

#include "../SDK/SDK.hpp"

namespace Cheat::Core::Interface
{
	inline struct Interfaces
	{
		CAPTURE_INTERFACE(baseClient,     SDK::Interface::BaseClient,     "client_panorama.dll", "VClient018");
		CAPTURE_INTERFACE(clientEntity,   SDK::Interface::ClientEntity,   "client_panorama.dll", "VClientEntityList003");
		CAPTURE_INTERFACE(cvar,           SDK::Interface::Cvar,           "vstdlib.dll",         "VEngineCvar007");
		CAPTURE_INTERFACE(debugOverlay,   SDK::Interface::DebugOverlay,   "engine.dll",          "VDebugOverlay004");
		CAPTURE_INTERFACE(engine,         SDK::Interface::Engine,         "engine.dll",          "VEngineClient014");
		CAPTURE_INTERFACE(inputSystem,    SDK::Interface::InputSystem,    "inputsystem.dll",     "InputSystemVersion001");
		CAPTURE_INTERFACE(materialSystem, SDK::Interface::MaterialSystem, "materialsystem.dll",  "VMaterialSystem080");
		CAPTURE_INTERFACE(panel,          SDK::Interface::Panel,          "vgui2.dll",           "VGUI_Panel009");
		CAPTURE_INTERFACE(renderView,     SDK::Interface::RenderView,     "engine.dll",          "VEngineRenderView014");
		CAPTURE_INTERFACE(sound,          SDK::Interface::Sound,          "engine.dll",          "IEngineSoundClient003");
		CAPTURE_INTERFACE(surface,        SDK::Interface::Surface,        "vguimatsurface.dll",  "VGUI_Surface031");
	} getInterfaces;
}
