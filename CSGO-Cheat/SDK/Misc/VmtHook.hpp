#pragma once
#pragma once

#include <memory>

namespace Cheat::SDK::Misc
{
	class VmtHook final
	{
	public:
		VmtHook() = default;

		explicit VmtHook(void* table)
		{
			base = static_cast<std::uintptr_t**>(table);

			while (static_cast<std::uintptr_t*>(*base)[size]) ++size;

			total = *base;
			current = std::make_unique< std::size_t[] >(size);

			std::memcpy(current.get(), total, size * sizeof(std::size_t));

			*base = current.get();
		}

		~VmtHook()
		{
			*base = total;
		}

		bool hookFunction(const std::size_t index, void* function) const
		{
			if (index > size) return false;

			current[index] = reinterpret_cast<std::uintptr_t>(function);

			return true;
		}

		[[nodiscard]] bool unhookFunction(const std::size_t index) const
		{
			if (index > size) return false;

			current[index] = total[index];

			return true;
		}

		template < typename T = void* > T getOriginalFunction(const std::size_t index)
		{
			return reinterpret_cast<T>(total[index]);
		}

	private:
		std::size_t      size  = 0;
		std::uintptr_t** base  = nullptr;
		std::uintptr_t*  total = nullptr;
		std::unique_ptr< std::uintptr_t[] > current = nullptr;
	};
}
