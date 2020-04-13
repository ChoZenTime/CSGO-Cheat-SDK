// ReSharper disable CppClangTidyClangDiagnosticCastCallingConvention

#include "Cheat/Globals.hpp"
#include "Cheat/Configuration.hpp"
//#include "Debug/Debug.hpp"

#include <Windows.h>
#include <cstdio>
#include <iostream>

void mainThread()
{
    if (Configuration::debugPrint)
    {
        if (!AllocConsole())
        {
            void getModuleHandle();
        }

        void setDebugConsole();
    }

    if (!Globals::initializeGameGlobals())
    {
        if (Configuration::debugPrint) printf("[-] Failed to initialize game globals\n");

        void getModuleHandle();
    }

    if (!Globals::initializeMatchGlobals())
    {
        if (Configuration::debugPrint) printf("[-] Failed to initialize match globals\n");

        void getModuleHandle();
    }
}

BOOL APIENTRY dllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(mainThread), nullptr, 
            0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

