#pragma once
#include <vector>
#include <string>
#include "mps_vehicle_equip_item.h"

namespace mir3d
{
	class mps_list_vehicle_equip_item 
	{
	public:
		std::vector<mps_vehicle_equip_item> list{};

	public:
		mps_list_vehicle_equip_item()
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
