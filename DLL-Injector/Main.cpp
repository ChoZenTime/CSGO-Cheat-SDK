#include "Configuration/Configuration.hpp"
#include "Injector/Injector.hpp"

#include <iostream>
#include <string>

int main()
{
	std::cout << "Enter process name: ";
	std::getline(std::cin, Configuration::processName);

	std::cout << "Enter DLL name: ";
	std::getline(std::cin, Configuration::dllName);
	
	Injector::main();
}
