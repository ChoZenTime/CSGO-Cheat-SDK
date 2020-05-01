#pragma once

#include <cstdint>

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/dt_recv.h

namespace Cheat::SDK::Interface
{
	struct RecvProxyData;
	struct RecvTable;
	struct RecvProp;

	using RecvVarProxy = void(__cdecl*)(const RecvProxyData*, void*, void*);
	using CreateClientClass = void* (*)(std::int32_t, std::int32_t);
	using CreateEvent = void* (*)();

	struct Variant
	{
		union
		{
			float floatType;

			long intType;

			char* stringType;

			void* dataType;

			float vectorType[3];

			__int64 int64Type;
		};

		std::int32_t type;
	};

	struct RecvProxyData
	{
		const RecvProp* prop;

		Variant value;

		std::int32_t element;
		std::int32_t objectId;
	};

	struct RecvTable
	{
		RecvProp* prop;

		std::int32_t props;

		void* decoder;

		char* netTableName;

		bool isInitialized;
		bool isInMainList;
	};

	struct RecvProp
	{
		char* variableName;

		std::int32_t recvType;
		std::int32_t flags;
		std::int32_t stringBufferSize;

		bool isInsideArray;

		const void* extraData;

		RecvProp* arrayProp;

		void* arrayLengthProxy;

		RecvVarProxy varProxy;

		void* dataTableProxy;

		RecvTable* dataTable;

		std::int32_t offset;
		std::int32_t elementStride;
		std::int32_t elements;

		const char* parentArrayPropName;
	};

	class ClientClass
	{
	public:
		CreateClientClass client;
		CreateEvent event;

		char* networkName;

		RecvTable* table;
		ClientClass* next;

		std::int32_t classId;
	};
}
