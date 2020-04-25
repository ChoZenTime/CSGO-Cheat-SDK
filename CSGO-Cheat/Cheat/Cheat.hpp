#pragma once

#include <Windows.h>

namespace Cheat
{
	void main(HMODULE module);
	void thread();
	void detach(HMODULE module);
}