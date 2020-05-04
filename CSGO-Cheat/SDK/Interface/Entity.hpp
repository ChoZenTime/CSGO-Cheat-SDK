#pragma once

#include "../Misc/NetvarTree.hpp"
#include "../Misc/Vector.hpp"

namespace Cheat::SDK::Interface
{
	struct Entity
	{
		NETVAR(health(), std::int32_t, "DT_BasePlayer", "m_iHealth")
		NETVAR(armorValue(), std::uint32_t, "DT_CSPlayer", "m_ArmorValue")
		NETVAR(flags(), std::int32_t, "DT_BasePlayer", "m_fFlags")
		NETVAR(team(), std::int32_t, "DT_BaseEntity", "m_iTeamNum")
		NETVAR(roundKills(), std::int32_t, "DT_CSPlayer", "m_iNumRoundKills")

		NETVAR(scoped(), bool, "DT_CSPlayer", "m_bIsScoped")
		NETVAR(controllingBot(), bool, "DT_CSPlayer", "m_bIsControllingBot")
		NETVAR(helmet(),        bool, "DT_CSPlayer", "m_bHasHelmet")
		NETVAR(defuseKit(),     bool, "DT_CSPlayer", "m_bHasDefuser")

		NETVAR(flashDuration(),                 float, "DT_CSPlayer", "m_bHasDefuser")
		NETVAR(flashAlpha(),                    float, "DT_CSPlayer", "m_flFlashMaxAlpha")
		NETVAR(healthShotBoostExpirationTime(), float, "DT_CSPlayer", "m_flHealthShotBoostExpirationTime")

		NETVAR(vecOrigin(), Misc::Vector, "DT_BaseEntity", "m_vecOrigin")

		OFFSET(dormant(), bool, 0xED)
	};
}
