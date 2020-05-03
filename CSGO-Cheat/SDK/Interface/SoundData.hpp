#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/SoundEmitterSystem/isoundemittersystembase.h

#include "../Misc/Macros.hpp"

namespace Cheat::SDK::Interface
{
	struct SoundData
	{
		PAD(pad1, 4) {};
		
		std::int32_t entityIndex {};
		std::int32_t channel     {};

		const char* soundEntry {};

		PAD(pad2, 8) {};

		float volume {};

		PAD(pad3, 44) {};
	};
}