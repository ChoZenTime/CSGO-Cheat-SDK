#pragma once

#include "../../Dependencies/Gui/FGUI.hh"

#include <memory>
#include <string>
#include <unordered_map>

namespace Cheat::Core::Menu
{
	inline std::unordered_map<std::string, std::shared_ptr<fgui::button      >> button;
	inline std::unordered_map<std::string, std::shared_ptr<fgui::checkbox    >> checkbox;
	inline std::unordered_map<std::string, std::shared_ptr<fgui::colorlist   >> colorList;
	inline std::unordered_map<std::string, std::shared_ptr<fgui::colorpicker >> colorPicker;
	inline std::unordered_map<std::string, std::shared_ptr<fgui::combobox    >> comboBox;
	inline std::unordered_map<std::string, std::shared_ptr<fgui::container   >> container;
	inline std::unordered_map<std::string, std::shared_ptr<fgui::keybinder   >> keyBinder;
	inline std::unordered_map<std::string, std::shared_ptr<fgui::label       >> label;
	inline std::unordered_map<std::string, std::shared_ptr<fgui::listbox     >> listBox;
	inline std::unordered_map<std::string, std::shared_ptr<fgui::multibox    >> multiBox;
	inline std::unordered_map<std::string, std::shared_ptr<fgui::slider      >> slider;
	inline std::unordered_map<std::string, std::shared_ptr<fgui::spinner     >> spinner;
	inline std::unordered_map<std::string, std::shared_ptr<fgui::tabs        >> tabs;
	inline std::unordered_map<std::string, std::shared_ptr<fgui::textbox     >> textBox;

	extern void render();
}