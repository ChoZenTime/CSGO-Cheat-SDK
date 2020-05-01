#include "Hooks.hpp"
#include "../Cheat/Interfaces.hpp"
#include "../Cheat/Memory.hpp"

namespace Cheat::Core::Hooks
{
	std::unique_ptr<SDK::Misc::VmtHook> client;
	std::unique_ptr<SDK::Misc::VmtHook> clientMode;
	std::unique_ptr<SDK::Misc::VmtHook> renderView;
	std::unique_ptr<SDK::Misc::VmtHook> sound;
	std::unique_ptr<SDK::Misc::VmtHook> panel;

	void createHooks()
	{
		SETUP_HOOK(client, Interface::getInterfaces.baseClient);
		if (client) HOOK_FUNCTION(client, 37, frameStageNotify);

		SETUP_HOOK(clientMode, Memory::getMemory.clientMode);
		if (clientMode)
		{
			HOOK_FUNCTION(clientMode, 24, createMove);
			HOOK_FUNCTION(clientMode, 18, overrideView);
		}

		SETUP_HOOK(renderView, Interface::getInterfaces.renderView);
		if (renderView) HOOK_FUNCTION(renderView, 9, sceneEnd);
		
		SETUP_HOOK(sound, Interface::getInterfaces.sound);
		if (sound) HOOK_FUNCTION(sound, 5, emitSound);
		
		SETUP_HOOK(panel, Interface::getInterfaces.panel);
		if (panel) HOOK_FUNCTION(panel, 41, paintTraverse);
	}

	void destroyHooks()
	{
		UNHOOK_FUNCTION(client, 37);
		UNHOOK_FUNCTION(clientMode, 24);
		UNHOOK_FUNCTION(clientMode, 18);
		UNHOOK_FUNCTION(renderView, 9);
		UNHOOK_FUNCTION(sound, 5);
		UNHOOK_FUNCTION(panel, 41);
	}
}