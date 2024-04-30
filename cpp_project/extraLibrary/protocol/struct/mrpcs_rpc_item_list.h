#pragma once
#include <vector>
#include <string>
#include "mrpcs_rpc_item.h"

namespace mir3d
{
	class mrpcs_rpc_item_list 
	{
	public:
		std::vector<mrpcs_rpc_item> list{};

	public:
		mrpcs_rpc_item_list()
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
