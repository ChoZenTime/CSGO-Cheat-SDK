#include "Cheat.hpp"
#include "Debug.hpp"

void Cheat::main(const HMODULE module)
{
	Debug::main();

	thread();

	detach(module);
}

/*void Cheat::attach()
{
	MessageBoxA(nullptr, "[-] Injected", "Cheat", 0);
}*/

void Cheat::detach(const HMODULE module)
{
	MessageBoxA(nullptr, "[-] Exited thread", "Cheat", 0);
	FreeLibraryAndExitThread(module, EXIT_SUCCESS);
}

void Cheat::thread()
{
	
}