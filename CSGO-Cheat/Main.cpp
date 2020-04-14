// ReSharper disable CppClangTidyClangDiagnosticCastCallingConvention

#include "Cheat/Globals.hpp"
#include "Cheat/Configuration.hpp"
#include "Cheat/Debug.hpp"

#include <Windows.h>
#include <cstdio>
#include <iostream>

void mainThread()
{
    if (Configuration::debugPrint)
    {
        if (!AllocConsole())
        {
            Debug::freeModule();
        }

        Debug::setDebugConsole();
    }

    if (!Globals::initializeGameGlobals())
    {
        if (Configuration::debugPrint) printf("[-] Failed to initialize game globals\n");

        Debug::freeModule();
    }

    if (!Globals::initializeMatchGlobals())
    {
        if (Configuration::debugPrint) printf("[-] Failed to initialize match globals\n");

        Debug::freeModule();
    }

    Debug::printDebugInfo();
}

BOOL APIENTRY DllMain(HMODULE module, DWORD callReason, LPVOID reserved)
{
    if (callReason == DLL_PROCESS_ATTACH)
    {
        CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(mainThread),
        nullptr, 0, nullptr);
    }

    return true;
}
