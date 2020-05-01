#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/const.h

namespace Cheat::SDK::Enum
{
	enum class Flags
	{
		OnGround            = (1 << 0) ,
		Ducking             = (1 << 1) ,
		WaterJump           = (1 << 2) ,
		OnTrain             = (1 << 3) ,
		InRain              = (1 << 4) ,
		Frozen              = (1 << 5) ,
		Controls            = (1 << 6) ,
		Client              = (1 << 7) ,
		FakeClient          = (1 << 8) ,
		InWater             = (1 << 9) ,
		Fly                 = (1 << 10),
		Swim                = (1 << 11),
		Conveyor            = (1 << 12),
		Npc                 = (1 << 13),
		GodMode             = (1 << 14),
		NoTarget            = (1 << 15),
		AimTarget           = (1 << 16),
		PartialGround       = (1 << 17),
		StaticProp          = (1 << 18),
		Graphed             = (1 << 19),
		Grenade             = (1 << 20),
		StepMovement        = (1 << 21),
		DoNotTouch          = (1 << 22),
		BaseVelocity        = (1 << 23),
		WorldBrush          = (1 << 24),
		Object              = (1 << 25),
		KillMe              = (1 << 26),
		OnFire              = (1 << 27),
		Dissolving          = (1 << 28),
		TransRagDoll        = (1 << 29),
		UnblockableByPlayer = (1 << 30)
	};
}
