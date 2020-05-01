#include "NetvarTree.hpp"
#include "../../Cheat/Interfaces.hpp"

// https://gist.github.com/AltimorTASDK/55b8b28e552eba0f6162

namespace Cheat::SDK::Misc
{
	NetvarTree::NetvarTree()
	{
		const auto* clientClass = Core::Interface::getInterfaces.baseClient->getAllClasses();

		while (clientClass != nullptr) 
		{
			const auto classInfo = std::make_shared<Node>(0);

			auto *recvTable = clientClass->table;

			populateNodes(recvTable, &classInfo->nodes);

			nodes.emplace(recvTable->netTableName, classInfo);

			clientClass = clientClass->next;
		}
	}

	void NetvarTree::populateNodes(Interface::RecvTable* recvTable, MapType* map) const
	{
		for (auto index = 0; index < recvTable->props; index++) 
		{
			const Interface::RecvProp* prop = &recvTable->prop[index];

			const auto propInfo = std::make_shared<Node>(prop->offset);

			if (prop->recvType == CONVERT_ENUM_TYPE(std::int32_t, Enum::SendPropType::DataTable))
			{
				populateNodes(prop->dataTable, &propInfo->nodes);
			}

			map->emplace(prop->variableName, propInfo);
		}
	}

	std::unique_ptr<NetvarTree> getNetvarTree;
}
