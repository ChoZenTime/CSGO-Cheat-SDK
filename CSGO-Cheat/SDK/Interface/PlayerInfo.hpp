#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/cdll_int.h

#include "../Misc/Macros.hpp"

namespace Cheat::SDK::Interface
{
	struct PlayerInfo
	{
		std::int64_t reserved;

		union
		{
			std::int64_t steamId64;
			std::int32_t xuIdLow;
			std::int32_t xuIdHigh;
		};

		char name[128];

		std::int32_t userId;

		char guid[20];

		PAD(pad, 16);

		unsigned long friendsId;

		char friendsName[128];

		bool fakePlayer;
		bool isHlTv;

		std::uint32_t customFiles[4];
		std::uint8_t filesDownloaded;
	};
}
