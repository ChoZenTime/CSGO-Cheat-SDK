#include "Cheat/Cheat.hpp"

#include <Windows.h>

void mainThread(const HMODULE module)
{
    Cheat::main(module);
}

BOOL APIENTRY DllMain(const HMODULE module, const DWORD callReason, const LPVOID reserved)
{
    if (callReason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(module);

        if (auto *const handle = CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(mainThread),nullptr, 0, nullptr))
        {
            CloseHandle(handle);
        }
    }

    return true;
}
