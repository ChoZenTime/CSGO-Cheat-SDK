#include "Entity.hpp"
#include "../Offsets/Offsets.h"
#include "../../Math/Vectors.h"

using namespace Cheat::Structures;

Entity *EntityList::entity(const std::uint32_t index) const noexcept
{
	return *reinterpret_cast<Entity**>(reinterpret_cast<std::uintptr_t>(this) + index * Offsets::entityListElementSize);
}

std::int32_t Entity::health() const noexcept
{
	return *reinterpret_cast<std::int32_t*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::m_iHealth);
}

bool Entity::dormant() const noexcept
{
	return *reinterpret_cast<bool*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::m_bDormant);
}

Vec3 Entity::vecOrigin() const noexcept
{
	return *reinterpret_cast<Vec3*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::m_vecOrigin);
}

std::int32_t Entity::teamNum() const noexcept 
{
	return *reinterpret_cast<uintptr_t*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::m_iTeamNum);
}

std::int32_t Entity::boneMatrix() const noexcept 
{
	return *reinterpret_cast<uintptr_t*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::m_dwBoneMatrix);
}

std::int32_t Entity::armorValue() const noexcept 
{
	return *reinterpret_cast<uintptr_t*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::m_ArmorValue);
}

Vec3 Entity::aimPunchAngle() const noexcept
{
	return *reinterpret_cast<Vec3*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::m_aimPunchAngle);
}

float Entity::angEyeAngles() const noexcept
{
	return *reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::m_angEyeAnglesX);
}

Vec3 Entity::vecVelocity() const noexcept
{
	return *reinterpret_cast<Vec3*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::m_vecVelocity);
}

bool Entity::hasHelmet() const noexcept
{
	return *reinterpret_cast<bool*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::m_bHasHelmet);
}

std::int32_t Entity::viewAngles() const noexcept
{
	return *reinterpret_cast<uintptr_t*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::dwClientState_ViewAngles);
}

std::int32_t Entity::clientState() const noexcept 
{
	return *reinterpret_cast<uintptr_t*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::dwClientState);
}

std::int32_t Entity::shotsFired() const noexcept
{
	return *reinterpret_cast<uintptr_t*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::m_iShotsFired);
}

std::int32_t Entity::flags() const noexcept
{
	return *reinterpret_cast<uintptr_t*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::m_fFlags);
}

std::int32_t Entity::forceJump() const noexcept
{
	return *reinterpret_cast<uintptr_t*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::dwForceJump);
}

std::int32_t Entity::localPlayer() const noexcept
{
	return *reinterpret_cast<uintptr_t*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::dwLocalPlayer);
}
