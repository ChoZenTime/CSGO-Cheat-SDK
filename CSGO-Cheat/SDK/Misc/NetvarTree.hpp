#pragma once

#include <memory>
#include <unordered_map>

// https://gist.github.com/AltimorTASDK/75fe97ff3174a7de3739

namespace Cheat::SDK::Interface
{
	struct RecvTable;
}

namespace Cheat::SDK::Misc
{
	class NetvarTree final
	{
		struct Node;

		using MapType = std::unordered_map<std::string, std::shared_ptr<Node>>;

		struct Node
		{
			explicit Node(const std::int32_t offset) : offset(offset) { }

			MapType nodes;

			std::int32_t offset;
		};

		MapType nodes{};

	public:
		NetvarTree();

		template <typename... T> std::int32_t getOffset(const char* name, T ... args)
		{
			const auto& node = nodes[name];

			return get_offset_recursive(node->nodes, node->offset, args...);
		}

	private:
		void populateNodes(Interface::RecvTable* recvTable, MapType* map) const;

		static std::int32_t get_offset_recursive(MapType& map, const std::int32_t acc, const char* name)
		{
			return acc + map[name]->offset;
		}

		template <typename... T> std::int32_t getOffsetRecursive(MapType& map, const std::int32_t acc, const char* name, T ... args) {
			const auto& node = map[name];

			return get_offset_recursive(node->nodes, acc + node->offset, args...);
		}
	};

	extern std::unique_ptr<NetvarTree> getNetvarTree;
}
