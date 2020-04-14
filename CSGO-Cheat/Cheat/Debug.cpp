#include "Globals.hpp"

#include "Debug.hpp"

#include <cstdio>
#include <iostream>

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

    const auto outputHandle = CreateFile(L"CONOUT$", GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL, nullptr);
    const auto inputHandle = CreateFile(L"CONIN$", GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL, nullptr);

    SetStdHandle(STD_OUTPUT_HANDLE, outputHandle);
    SetStdHandle(STD_ERROR_HANDLE,  outputHandle);
    SetStdHandle(STD_INPUT_HANDLE,  inputHandle);
}

void Debug::printDebugInfo()
{
    printf("entity list: %p\n", Globals::entityList);

    const auto entity = Globals::entityList->entity(0);

    if (!entity)
    {
        printf("[-] Could not retrieve the first entity\n");
        return;
    }

    printf("First entity:\nhealth: %i\nteam: %i\nhelmet: %s\n", entity->health(), entity->teamNum(), entity->hasHelmet() ? "true" : "false");
}
