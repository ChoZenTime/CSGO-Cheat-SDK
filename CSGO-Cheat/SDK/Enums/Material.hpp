#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/materialsystem/imaterial.h

namespace Cheat::SDK::Enum
{
	enum class Material
	{
		Debug                    = (1 << 0),
		NoDebugOverride          = (1 << 1),
		NoDraw                   = (1 << 2),
		UseInFillRateMode        = (1 << 3),
		VertexColor              = (1 << 4),
		VertexAlpha              = (1 << 5),
		SelfIllum                = (1 << 6),
		Additive                 = (1 << 7),
		Alphatest                = (1 << 8),
		MultiPass                = (1 << 9),
		Znearer                  = (1 << 10),
		Model                    = (1 << 11),
		Flat                     = (1 << 12),
		NoCull                   = (1 << 13),
		NoFog                    = (1 << 14),
		Ignorez                  = (1 << 15),
		Decal                    = (1 << 16),
		EnvMapSphere             = (1 << 17),
		NoAlphaMod               = (1 << 18),
		EnvMapCameraSpace        = (1 << 19),
		BaseAlphaEnvMapMask      = (1 << 20),
		TransLucent              = (1 << 21),
		NormalMapAlphaEnvMapMask = (1 << 22),
		NeedsSoftwareSkinning    = (1 << 23),
		OpaqueTexture            = (1 << 24),
		EnvMapMode               = (1 << 25),
		SuppressDecals           = (1 << 26),
		HalfLabert               = (1 << 27),
		WireFrame                = (1 << 28),
		AllowAlphaToCoverage     = (1 << 29),
		IgnoreAlphaModulation    = (1 << 30),
	};
}
