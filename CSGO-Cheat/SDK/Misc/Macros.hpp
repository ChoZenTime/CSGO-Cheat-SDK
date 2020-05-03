#pragma once

#include "CaptureInterface.hpp"
#include "NetvarTree.hpp"
#include "VfuncFromIndex.hpp"
#include "VmtHook.hpp"

#define REGISTERS \
	std::uintptr_t ecx, std::uintptr_t edx

#define PAD(variable_name, size) \
	std::byte variable_name[size]

#define CAPTURE_INTERFACE(variableName, interfaceStruct, interfaceModule, interfaceName) \
	interfaceStruct* variableName = Cheat::SDK::Misc::captureInterface<interfaceStruct*>(interfaceModule, interfaceName)

#define MEMORY_POINTER(variableName, interfaceStruct, interfacePointer, base, offset) \
	interfaceStruct* variableName = **reinterpret_cast<interfaceStruct***>((*reinterpret_cast<std::uintptr_t**>(interfacePointer))[base] + (offset))

#define SETUP_HOOK(hookPointer, interfacePointer) \
	hookPointer = std::make_unique<Cheat::SDK::Misc::VmtHook>(interfacePointer)

#define HOOK_FUNCTION( variableName, index, functionName ) \
	variableName->hookFunction(index, reinterpret_cast<void*>(functionName))

#define UNHOOK_FUNCTION(variableName, index) \
	variableName->unhookFunction(index)

#define GET_ORIGINAL_FUNCTION(variableName, index, type, ...) \
	variableName->getOriginalFunction<type>(index)(__VA_ARGS__)

#define RETURN_ORIGINAL_FUNCTION(variableName, index, type, ...) \
	return variableName->getOriginalFunction<type>(index)(__VA_ARGS__)

#define NETVAR(functionName, type, ...) \
	type& functionName \
	{ \
		return *reinterpret_cast<type*>(reinterpret_cast<std::uintptr_t>(this) + Cheat::SDK::Misc::getNetvarTree->getOffset(__VA_ARGS__)); \
	};

#define OFFSET(functionName, type, offset) \
	type& (functionName) \
	{ \
		return *reinterpret_cast<type*>(std::uintptr_t(this) + offset); \
	};

#define VFUNC(functionName, index, type, ...) \
	auto functionName \
	{ \
		return Cheat::SDK::Misc::vfuncFromIndex<type>(this, index)(this, __VA_ARGS__); \
	};

#define CONVERT_ENUM_TYPE(type, enumClass) \
	static_cast<type>(enumClass)