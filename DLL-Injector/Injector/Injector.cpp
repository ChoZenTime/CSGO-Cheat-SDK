#include "Injector.hpp"
#include "../Configuration/Configuration.hpp"

#include <TlHelp32.h>
#include <filesystem>

std::uint32_t Injector::findProcess(const std::string_view processName)
{
	auto* const processSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (processSnapshot == INVALID_HANDLE_VALUE) return false;

	auto processEntry = PROCESSENTRY32{ sizeof(PROCESSENTRY32) };

	if (Process32First(processSnapshot, &processEntry))
	{
		do
		{
			if (!strcmp(processEntry.szExeFile, processName.data()))
			{
				CloseHandle(processSnapshot);
				
				return processEntry.th32ParentProcessID;
			}
		} while (Process32Next(processSnapshot, &processEntry));
	}
	CloseHandle(processSnapshot);

	return 0;
}

auto Injector::detach(const HANDLE process, const LPVOID path, const HANDLE thread) -> void  // NOLINT(misc-misplaced-const)
{
	if (path)    VirtualFreeEx(process, path, 0, MEM_RELEASE);
	if (thread)  CloseHandle(thread);
	if (process) CloseHandle(process);
}

BOOL Injector::main()
{
	HANDLE process {};
	LPVOID path    {};
	HANDLE thread  {};

	try
	{
		const auto filePath = std::filesystem::canonical(Configuration::dllName).wstring();
		if (!std::filesystem::exists(filePath)) throw std::runtime_error("[ - ] Failed to find target file");

		const auto processId = findProcess(std::string_view{Configuration::processName});
		if (!processId) throw std::runtime_error("[ - ] Target process is not open");

		process = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_CREATE_THREAD, FALSE, processId);
		if (!process) throw std::runtime_error("[ - ] Failed to open process handle");

		path = VirtualAllocEx(process, nullptr, filePath.size() * 2, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
		if (!path) throw std::runtime_error("[ - ] Failed to allocate memory");

		if (!WriteProcessMemory(process, path, filePath.c_str(), filePath.size() * 2, nullptr)) throw std::runtime_error("[ - ] Failed to write dll path into process.");

		thread = CreateRemoteThread(process, nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(LoadLibraryW), path, NULL, nullptr);
		if (!thread) throw std::runtime_error("[ - ] Failed to open remote thread");

		WaitForSingleObject(thread, INFINITE);

		MessageBoxA(nullptr, "[-] Successfully Injected", "Cheat", 0);

		detach(process, path, thread);
	}	
	catch (const std::runtime_error& error)
	{
		detach(process, path, thread);

		MessageBoxA(nullptr, error.what(), "Cheat", 0);

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
