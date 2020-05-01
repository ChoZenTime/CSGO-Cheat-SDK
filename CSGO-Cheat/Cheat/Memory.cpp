#include "Memory.hpp"

bool Cheat::Core::Memory::valid(const std::uintptr_t pointer)
{
	MEMORY_BASIC_INFORMATION memoryInfo{};

	const auto returnSize = VirtualQuery(reinterpret_cast<LPCVOID>(pointer), &memoryInfo, sizeof(memoryInfo));

	if (returnSize != sizeof(memoryInfo)) return false;
	if (!(memoryInfo.State & MEM_COMMIT)) return false;
	if (memoryInfo.Protect & PAGE_GUARD || !(memoryInfo.Protect & (PAGE_READONLY | PAGE_READWRITE))) return false;

	return true;
}

bool Cheat::Core::Memory::edit(void* memory, void* source, const DWORD length)
{
	DWORD oldProtection {};

	if (VirtualProtect(memory, length, PAGE_EXECUTE_READWRITE, &oldProtection))
	{
		for (size_t index = 0; index < length; index++)
		{
			*reinterpret_cast<BYTE*>(reinterpret_cast<DWORD>(memory) + index) = *reinterpret_cast<BYTE*>(reinterpret_cast<DWORD>(source) + index);
		}

		VirtualProtect(memory, length, oldProtection, &oldProtection);

		return true;
	}

	return false;
}

void Cheat::Core::Memory::patch(BYTE* destination, BYTE* source, const uint16_t length)
{
	DWORD oldProtection {};
	VirtualProtect(destination, length, PAGE_EXECUTE_READWRITE, &oldProtection);

	memcpy(destination, source, length);
	VirtualProtect(destination, length, oldProtection, &oldProtection);
}