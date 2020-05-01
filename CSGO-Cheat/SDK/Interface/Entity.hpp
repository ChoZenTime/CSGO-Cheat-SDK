#pragma once

#include "../Misc/NetvarTree.hpp"
#include "../Misc/Vector.hpp"

namespace Cheat::SDK::Interface
{
	struct Entity
	{
		NETVAR(health(),        std::int32_t,  "DT_BasePlayer", "m_iHealth");
		NETVAR(getArmorValue(), std::uint32_t, "DT_CSPlayer",   "m_ArmorValue");
		NETVAR(getFlags(),      std::int32_t,  "DT_BasePlayer", "m_fFlags");
		NETVAR(getTeam(),       std::int32_t,  "DT_BaseEntity", "m_iTeamNum");
		NETVAR(getRoundKills(), std::int32_t,  "DT_CSPlayer",   "m_iNumRoundKills");

		NETVAR(isScoped(),         bool, "DT_CSPlayer", "m_bIsScoped");
		NETVAR(isControllingBot(), bool, "DT_CSPlayer", "m_bIsControllingBot");
		NETVAR(hasHelmet(),        bool, "DT_CSPlayer", "m_bHasHelmet");
		NETVAR(hasDefuseKit(),     bool, "DT_CSPlayer", "m_bHasDefuser");

		NETVAR(getFlashDuration(),                 float, "DT_CSPlayer", "m_bHasDefuser");
		NETVAR(getFlashAlpha(),                    float, "DT_CSPlayer", "m_flFlashMaxAlpha");
		NETVAR(getHealthShotBoostExpirationTime(), float, "DT_CSPlayer", "m_flHealthShotBoostExpirationTime");

		NETVAR(getVecOrigin(), Misc::Vector, "DT_BaseEntity", "m_vecOrigin")

		OFFSET(isDormant(), bool, 0xED)
	};
}
