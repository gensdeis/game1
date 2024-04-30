#pragma once
#include <vector>
#include <string>
#include "mps_exchange_search_item.h"

namespace mir3d
{
	class mps_exchange_search_item_list 
	{
	public:
		std::vector<mps_exchange_search_item> list{};

	public:
		mps_exchange_search_item_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
