#include "Aimbot.hpp"
#include "../../Interfaces.hpp"
#include "../../../Memory/Memory.hpp"
#include "../../../Menu/Menu.hpp"
#include "../../../SDK/Math/Math.hpp"

// TODO: Fix
void Aimbot::rage(Cheat::SDK::Interface::UserCmd* cmd)
{
	if (!Cheat::Core::Menu::checkbox["#rageCheckbox"]->get_bool()) return;

	auto* target = Aimbot::target();

	auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());

	if (Cheat::Core::Memory::valid(reinterpret_cast<std::uintptr_t>(target)) && Cheat::Core::Memory::valid(reinterpret_cast<std::uintptr_t>(localPlayer)))
	{
		const auto viewAngles = Math::calculateAngle(localPlayer->vecOrigin(), target->vecOrigin());
		cmd->viewAngles = viewAngles;
	}
}

Cheat::SDK::Interface::Entity* Aimbot::target()
{
	auto oldDelta = FLT_MAX;

	Cheat::SDK::Interface::Entity* target {};
	
	auto* localPlayer = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(Cheat::Core::Interface::getInterfaces.engine->getLocalPlayer());
	
	for (auto index = 1; index <= Cheat::Core::Memory::getMemory.globalVariables->maxClients; index++)
	{
		auto* entity = Cheat::Core::Interface::getInterfaces.clientEntity->getClientEntity(index);

		if (!entity && !entity->health() > 0 && entity != localPlayer)
		{
			auto angle = Math::calculateAngle(localPlayer->vecOrigin(), entity->vecOrigin());

			Cheat::SDK::Misc::Vector localEntityViewAngles{};
			Cheat::Core::Interface::getInterfaces.engine->getViewAngles(localEntityViewAngles);

			const auto newDelta = Math::distance(localEntityViewAngles, angle);

			if (newDelta < oldDelta)
			{
				oldDelta = newDelta;
				target   = entity;    // Add index
			}
		}
	}

	return target;
}	
