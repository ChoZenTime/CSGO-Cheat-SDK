#pragma once

#include "../../Dependencies/Gui/FGUI.hh"
#include "../Misc/Macros.hpp"

namespace Cheat::SDK::Interface
{
	struct Surface
	{
		OFFSET(clippingEnabled(), bool, 0x280);
		
		VFUNC(drawSetColor(const std::int32_t r, const std::int32_t g, const std::int32_t b, const std::int32_t a), 15, void(__thiscall*)(void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t), r, g, b, a);
		VFUNC(drawFilledRectangle(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h), 16, void(__thiscall*)(void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t), x, y, w, h);
		VFUNC(drawOutlinedRectangle(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h), 18, void(__thiscall*)(void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t), x, y, w, h);
		VFUNC(drawLine(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h), 19, void(__thiscall*)(void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t), x, y, w, h);
		VFUNC(drawSetTextFont(const unsigned long font), 23, void(__thiscall*)(void*, unsigned long), font);
		VFUNC(drawSetTextColor(const std::int32_t r, const std::int32_t g, const std::int32_t b, const std::int32_t a), 25, void(__thiscall*)(void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t), r, g, b, a);
		VFUNC(drawSetTextPos(const std::int32_t x, const std::int32_t y), 26, void(__thiscall*)(void*, std::int32_t, std::int32_t), x, y);
		VFUNC(drawPrintText(const wchar_t* text, const std::int32_t len), 28, void(__thiscall*)(void*, const wchar_t*, std::int32_t, std::int32_t), text, len, 0);
		VFUNC(drawSetTextureFile(const std::int32_t textureId, const char* textureName, const std::int32_t hardwareFilter, const bool forceReload), 36, void(__thiscall*)(void*, std::int32_t, const char*, std::int32_t, bool), textureId, textureName, hardwareFilter, forceReload);
		VFUNC(drawSetTextureRgba(const std::int32_t textureId, unsigned const char* rgbaData, const std::int32_t width, const std::int32_t height), 37, void(__thiscall*)(void*, std::int32_t, unsigned const char*, std::int32_t, std::int32_t), textureId, rgbaData, width, height);
		VFUNC(drawSetTexture(const std::int32_t textureId), 38, void(__thiscall*)(void*, std::int32_t), textureId);
		VFUNC(drawTexturedRectangle(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h), 41, void(__thiscall*)(void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t), x, y, w, h);
		VFUNC(isTextureIdValid(const std::int32_t textureId), 42, bool(__thiscall*)(void*, std::int32_t), textureId);
		VFUNC(createNewTextureId(const bool isProcedural), 43, std::int32_t(__thiscall*)(void*, bool), isProcedural);
		VFUNC(getScreenSize(std::int32_t& x, std::int32_t& y), 44, void(__thiscall*)(void*, std::int32_t&, std::int32_t&), x, y);
		VFUNC(createFont(), 71, unsigned long(__thiscall*)(void*));
		VFUNC(setFontGlyphSet(const unsigned long font, const char* fontName, const std::int32_t tall, const std::int32_t weight, const std::int32_t blur, const std::int32_t scanLines, const std::int32_t flags, const std::int32_t minRange, const std::int32_t maxRange), 72, void(__thiscall*)(void*, unsigned long, const char*, std::int32_t, std::int32_t, std::int32_t, std::int32_t, std::int32_t, std::int32_t, std::int32_t), font, fontName, tall, weight, blur, scanLines, flags, minRange, maxRange);
		VFUNC(getTextSize(const unsigned long font, const wchar_t* text, std::int32_t& wide, std::int32_t& tall), 79, void(__thiscall*)(void*, unsigned long, const wchar_t*, std::int32_t&, std::int32_t&), font, text, wide, tall);
		VFUNC(playSoundound(const char* fileName), 82, void(__thiscall*)(void*, const char*), fileName);
		VFUNC(getCursorPosition(std::int32_t& x, std::int32_t& y), 100, void(__thiscall*)(void*, std::int32_t&, std::int32_t&), x, y);
		VFUNC(drawOutlinedCircle(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h), 103, void(__thiscall*)(void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t), x, y, w, h);
		VFUNC(drawTexturedPolygon(const std::int32_t vertexCount, fgui::vertex* vertex, const bool clipVertices), 106, void(__thiscall*)(void*, std::int32_t, fgui::vertex*, bool), vertexCount, vertex, clipVertices);
		VFUNC(drawFilledRectangleFade(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const std::int32_t firstAlpha, const std::int32_t secondAlpha, const bool isHorizontal), 123, void(__thiscall*)(void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t, std::uint32_t, std::uint32_t, bool), x, y, w, h, firstAlpha, secondAlpha, isHorizontal);
		VFUNC(getClipRectangle(std::int32_t& x, std::int32_t& y, std::int32_t& w, std::int32_t& h), 146, void(__thiscall*)(void*, std::int32_t&, std::int32_t&, std::int32_t&, std::int32_t&), x, y, w, h);
		VFUNC(setClipRectangle(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h), 147, void(__thiscall*)(void*, std::int32_t, std::int32_t, std::int32_t, std::int32_t), x, y, w, h);
	};
}