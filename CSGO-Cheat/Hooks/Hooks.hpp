#pragma once

#include "../SDK/SDK.hpp"

#include <cstdint>
#include <memory>

namespace Cheat::Core::Hooks
{
	extern std::unique_ptr<SDK::Misc::VmtHook> client;
	extern std::unique_ptr<SDK::Misc::VmtHook> clientMode;
	extern std::unique_ptr<SDK::Misc::VmtHook> renderView;
	extern std::unique_ptr<SDK::Misc::VmtHook> sound;
	extern std::unique_ptr<SDK::Misc::VmtHook> panel;

	extern void __fastcall frameStageNotify(REGISTERS, SDK::Enum::ClientFrameStage);
	extern bool __fastcall createMove      (REGISTERS, float, SDK::Interface::UserCmd*);
	extern void __fastcall overrideView    (REGISTERS, SDK::Interface::ViewSetup*);
	extern void __fastcall sceneEnd        (REGISTERS);
	extern void __fastcall emitSound       (REGISTERS, SDK::Interface::SoundData);
	extern void __fastcall paintTraverse   (REGISTERS, std::int32_t, bool, bool);

	extern void create();
	extern void destroy();
}