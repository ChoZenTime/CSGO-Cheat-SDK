#include "Cheat/Cheat.hpp"

BOOL APIENTRY DllMain(const HMODULE module, const DWORD callReason, LPVOID reserved)
{
		if (callReason == DLL_PROCESS_ATTACH)
		{
			DisableThreadLibraryCalls(module);

			auto *const handle = CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(Cheat::Core::attach),
				module, 0, nullptr);
			if (handle) CloseHandle(handle);
		}

		return TRUE;
}