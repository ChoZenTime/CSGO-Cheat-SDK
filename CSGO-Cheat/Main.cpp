#include "Cheat/Cheat.hpp"

BOOL WINAPI DllMain(HINSTANCE const* instance, const DWORD reason, LPVOID const* reserved)
{
	switch (reason) 
	{
		case DLL_PROCESS_ATTACH:
		{
			auto *const thread = CreateThread(nullptr, 0, Cheat::Core::attach, *instance, 0, nullptr);
			if (thread != nullptr) CloseHandle(thread);
		} break;

		case DLL_PROCESS_DETACH:
		{
			if (!reserved) Cheat::Core::detach();
		} break;

		default: break;
	}

	return EXIT_SUCCESS;
}