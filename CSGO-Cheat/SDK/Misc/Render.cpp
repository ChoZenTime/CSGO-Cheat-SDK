#include "Render.hpp"
#include "Macros.hpp"

#include "../../Cheat/Configuration.hpp"

namespace Cheat::SDK::Misc
{
	void createFont(fgui::font& font, const std::string_view family, const std::int32_t size, const std::int32_t flags, const bool bold)
	{
		font = Core::Interface::getInterfaces.surface->createFont();

		Core::Interface::getInterfaces.surface->setFontGlyphSet(font, family.data(), size, bold ? 800 : 0, 0, 0, flags, 0, 0);
	}

	void getScreenSize(std::int32_t& x, std::int32_t& y)
	{
		Core::Interface::getInterfaces.surface->getScreenSize(x, y);
	}

	fgui::dimension getTextSize(const fgui::font& font, const std::string_view text)
	{
		fgui::dimension dimension = { 0, 0 };

		Core::Interface::getInterfaces.surface->getTextSize(font, std::wstring(text.begin(), text.end()).data(), dimension.width, dimension.height);

		return dimension;
	}

	void rectangle(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const fgui::color color)
	{
		Core::Interface::getInterfaces.surface->drawSetColor(color.m_red, color.m_green, color.m_blue, color.m_alpha);
		Core::Interface::getInterfaces.surface->drawFilledRectangle(x, y, x + w, y + h);
	}

	void outlinedRectangle(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const fgui::color color)
	{
		Core::Interface::getInterfaces.surface->drawSetColor(color.m_red, color.m_green, color.m_blue, color.m_alpha);
		Core::Interface::getInterfaces.surface->drawOutlinedRectangle(x, y, x + w, y + h);
	}

	void line(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const fgui::color color)
	{
		Core::Interface::getInterfaces.surface->drawSetColor(color.m_red, color.m_green, color.m_blue, color.m_alpha);
		Core::Interface::getInterfaces.surface->drawLine(x, y, w, h);
	}

	void polygon(const std::int32_t count, fgui::vertex* vertex, const fgui::color color)
	{
		static auto texture = Core::Interface::getInterfaces.surface->createNewTextureId(true);

		std::uint8_t buffer[4] = { 255, 255, 255, 255 };

		Core::Interface::getInterfaces.surface->drawSetTextureRgba(texture, buffer, 1, 1);
		Core::Interface::getInterfaces.surface->drawSetColor(color.m_red, color.m_green, color.m_blue, color.m_alpha);
		Core::Interface::getInterfaces.surface->drawSetTexture(texture);
		Core::Interface::getInterfaces.surface->drawTexturedPolygon(count, vertex, true);
	}

	void text(const std::int32_t x, const std::int32_t y, const fgui::color color, const unsigned long font, const std::string_view text)
	{
		const auto convertedText = std::wstring(text.begin(), text.end());

		Core::Interface::getInterfaces.surface->drawSetTextColor(color.m_red, color.m_green, color.m_blue, color.m_alpha);
		Core::Interface::getInterfaces.surface->drawSetTextFont(font);
		Core::Interface::getInterfaces.surface->drawSetTextPos(x, y);
		Core::Interface::getInterfaces.surface->drawPrintText(convertedText.c_str(), std::wcslen(convertedText.c_str()));
	}

	void circle(const std::int32_t x, const std::int32_t y, const std::int32_t radius, const std::int32_t segments, const fgui::color color)
	{
		Core::Interface::getInterfaces.surface->drawSetColor(color.m_red, color.m_green, color.m_blue, color.m_alpha);
		Core::Interface::getInterfaces.surface->drawOutlinedCircle(x, y, radius, segments);
	}

	void gradient(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const std::int32_t firstAlpha, const std::int32_t secondAlpha, const fgui::color color, const bool horizontal)
	{
		Core::Interface::getInterfaces.surface->drawSetColor(color.m_red, color.m_green, color.m_blue, color.m_alpha);
		Core::Interface::getInterfaces.surface->drawFilledRectangleFade(x, y, x + w, y + h, firstAlpha, secondAlpha, horizontal);
	}

	void coloredGradient(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h, const fgui::color firstColor, const fgui::color secondColor, const bool isHorizontal)
	{
		if (isHorizontal) {
			rectangle(x, y, w, h, firstColor);

			for (auto i = 0; i < w; i++)
				rectangle(x + i, y, 1, h, fgui::color(secondColor.m_red, secondColor.m_red, secondColor.m_blue, i / w * 255));
		}
		else {
			rectangle(x, y, w, h, firstColor);

			for (auto i = 0; i < w; i++)
				rectangle(x, y + i, w, 1, fgui::color(secondColor.m_red, secondColor.m_red, secondColor.m_blue, i / w * 255));
		}
	}

	void getAlphaValue(const std::int32_t x, const std::int32_t y, const std::int32_t w, const std::int32_t h)
	{
		for (auto i = 0; i < h / 5; i++) {
			for (auto t = 0; t < w / 5; t++) {
				const auto pixel = static_cast<std::int32_t>(std::roundf(t));
				const auto line = static_cast<std::int32_t>(std::roundf(i));
				const auto isBrickLight = line % 2 ? pixel % 2 : pixel % 2 == 0;
				const auto newColor = isBrickLight ? fgui::color(60, 60, 60) : fgui::color(40, 40, 40);

				rectangle(x + t * 5, y + i * 5, 5, 5, newColor);
			}
		}
	}

	void clipRectangle(const std::int32_t x, const std::int32_t y, const std::int32_t width, const std::int32_t height)
	{
		const fgui::rect viewport = { x, y, (x + width), (y + height) };

		Core::Interface::getInterfaces.surface->setClipRectangle(viewport.left, viewport.top, viewport.right, viewport.bottom);
	}

	void setupRenderFunctions()
	{
		fgui::render.create_font      = createFont;
		fgui::render.get_screen_size  = getScreenSize;
		fgui::render.get_text_size    = getTextSize;
		fgui::render.rect             = rectangle;
		fgui::render.gradient         = gradient;
		fgui::render.colored_gradient = coloredGradient;
		fgui::render.outline          = outlinedRectangle;
		fgui::render.line             = line;
		fgui::render.polygon          = polygon;
		fgui::render.circle           = circle;
		fgui::render.text             = text;
		fgui::render.alpha            = getAlphaValue;
		fgui::render.clip_rect        = clipRectangle;

		fonts.push_back(CONVERT_ENUM_TYPE(std::int32_t, Enum::Font::Watermark));
		fonts.push_back(CONVERT_ENUM_TYPE(std::int32_t, Enum::Font::Visuals));

		fgui::render.create_font(fonts[CONVERT_ENUM_TYPE(std::int32_t, Enum::Font::Watermark)], Configuration::watermarkFont);
		fgui::render.create_font(fonts[CONVERT_ENUM_TYPE(std::int32_t, Enum::Font::Visuals)], Configuration::visualsFont);
	}
}
