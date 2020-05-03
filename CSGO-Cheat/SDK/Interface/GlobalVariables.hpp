#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/globalvars_base.h

#include <cstdint>

namespace Cheat::SDK::Interface
{
	struct GlobalVariables
	{
		float realTime {};

		std::int32_t frameCount {};

		float absoluteFrameTime      {};
		float absoluteFrameStartTime {};
		float curTime   {};
		float frameTime {};

		std::int32_t maxClients {};
		std::int32_t tickCount  {};

		float intervalPerTick    {};
		float interpolationCount {};

		std::int32_t simTicksThisFrame {};
		std::int32_t networkProtocol   {};

		void* saveData {};

		bool client       {};
		bool removeClient {};

		std::int32_t timeStampNetworkingBase  {};
		std::int32_t timeStampRandomizeWindow {};
	};
}
