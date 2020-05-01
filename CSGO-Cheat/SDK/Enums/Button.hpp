#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/game/shared/in_buttons.h#L15

namespace Cheat::SDK::Enum
{
	enum class Button
	{
		Attack        = (1 << 0) ,
		Jump          = (1 << 1) ,
		Duck          = (1 << 2) ,
		Forward       = (1 << 3) ,
		Back          = (1 << 4) ,
		Use           = (1 << 5) ,
		Cancel        = (1 << 6) ,
		Left          = (1 << 7) ,
		Right         = (1 << 8) ,
		MoveLeft      = (1 << 9) ,
		MoveRight     = (1 << 10),
		RightAttack   = (1 << 11),
		Run           = (1 << 12),
		Reload        = (1 << 13),
		LeftAlt       = (1 << 14),
		RightAlt      = (1 << 15),
		Score         = (1 << 16),
		Speed         = (1 << 17),
		Walk          = (1 << 18),
		Zoom          = (1 << 19),
		FirstWeapon   = (1 << 20),
		SecondWeapon  = (1 << 21),
		BullRush      = (1 << 22),
		FirstGrenade  = (1 << 23),
		SecondGrenade = (1 << 24),
		MiddleAttack  = (1 << 25)
	};
}
