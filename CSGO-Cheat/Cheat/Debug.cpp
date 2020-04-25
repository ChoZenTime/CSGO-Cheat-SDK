#include "Debug.hpp"
#include "Configuration.hpp"

#include <cstdio>
#include <iostream>

void Debug::main()
{
    if (Configuration::debugPrint)
    {
        if (!AllocConsole())
        {
            freeModule();
        }

        setDebugConsole();
    }

    // TODO: Add debug checks

    printDebugInfo();

}

void Debug::freeModule()
{
	HMODULE moduleHandle{};
    GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, reinterpret_cast<LPCWSTR>(DllMain), &moduleHandle);
    FreeLibraryAndExitThread(moduleHandle, 0);
}

void Debug::setDebugConsole()
{
	FILE* file{};
    freopen_s(&file, "CONOUT$", "w", stdout);
    freopen_s(&file, "CONOUT$", "w", stderr);
    freopen_s(&file, "CONIN$",  "r", stdin);
    std::cout.clear(); std::clog.clear(); std::cerr.clear(); std::cin.clear();

    auto *const outputHandle = CreateFile(L"CONOUT$", GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL, nullptr);
    auto* const inputHandle = CreateFile(L"CONIN$", GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL, nullptr);

    SetStdHandle(STD_OUTPUT_HANDLE, outputHandle);
    SetStdHandle(STD_ERROR_HANDLE,  outputHandle);
    SetStdHandle(STD_INPUT_HANDLE,  inputHandle);
}

void Debug::printDebugInfo()
{
    // TODO: Add debug info
}
