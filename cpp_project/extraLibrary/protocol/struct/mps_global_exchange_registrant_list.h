#pragma once
#include <vector>
#include <string>
#include "mps_global_exchange_registrant_item.h"

namespace mir3d
{
	class mps_global_exchange_registrant_list 
	{
	public:
		std::vector<mps_global_exchange_registrant_item> list{};

	public:
		mps_global_exchange_registrant_list()
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
