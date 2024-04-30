#pragma once
#include <vector>
#include <string>
#include "mps_comm_equip.h"

namespace mir3d
{
	class mps_comm_equip_list 
	{
	public:
		std::vector<mps_comm_equip> list{};

	public:
		mps_comm_equip_list()
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
