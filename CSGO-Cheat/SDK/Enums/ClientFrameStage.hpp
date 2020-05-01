#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/cdll_int.h

namespace Cheat::SDK::Enum
{
	enum class ClientFrameStage
	{
		Undefined = -1,
		Start,
		NetUpdateStart,
		NetUpdatePostDataUpdateStart,
		NetUpdatePostDataUpdateEnd,
		NetUpdateEnd,
		RenderStart,
		RenderEnd
	};
}
