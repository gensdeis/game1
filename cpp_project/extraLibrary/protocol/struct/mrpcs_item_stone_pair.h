#pragma once
#include <vector>
#include <string>
#include "mps_item.h"

namespace mir3d
{
	class mrpcs_item_stone_pair 
	{
	public:
		int64_t iuid{};
	public:
		std::vector<mps_item> list_stone{};

	public:
		mrpcs_item_stone_pair()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &list_stone);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
