#pragma once

#include "../../Math/Vectors.h"

#include <cstdint>

namespace Cheat::Structures
{
	struct Entity
	{
		[[nodiscard]] std::int32_t health()      const noexcept;		
		[[nodiscard]] std::int32_t teamNum()     const noexcept;	
		[[nodiscard]] std::int32_t boneMatrix()  const noexcept;
		[[nodiscard]] std::int32_t armorValue()  const noexcept;	
		[[nodiscard]] std::int32_t viewAngles()  const noexcept;
		[[nodiscard]] std::int32_t localPlayer() const noexcept;
		[[nodiscard]] std::int32_t clientState() const noexcept;
		[[nodiscard]] std::int32_t shotsFired()  const noexcept;
		[[nodiscard]] std::int32_t flags()		 const noexcept;
		[[nodiscard]] std::int32_t forceJump()   const noexcept;
		
		[[nodiscard]] bool dormant()             const noexcept;
		[[nodiscard]] bool hasHelmet()			 const noexcept;
		[[nodiscard]] float angEyeAngles()       const noexcept;
		
		[[nodiscard]] Vec3 aimPunchAngle()       const noexcept;
		[[nodiscard]] Vec3 vecVelocity()         const noexcept;
		[[nodiscard]] Vec3 vecOrigin()           const noexcept;	

	};

	struct EntityList
	{
		[[nodiscard]] Entity* entity(std::uint32_t index) const noexcept;
	};
}