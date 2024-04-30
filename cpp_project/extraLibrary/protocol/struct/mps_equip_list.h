#pragma once
#include <vector>
#include <string>
#include "mps_equip_item_info.h"

namespace mir3d
{
	class mps_equip_list 
	{
	public:
		std::vector<mps_equip_item_info> equip_info{};

	public:
		mps_equip_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &equip_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
