#pragma once
#include <vector>
#include <string>
#include "mps_equip_info.h"

namespace mir3d
{
	class mps_equip_info_list 
	{
	public:
		std::vector<mps_equip_info> list{};

	public:
		mps_equip_info_list()
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
