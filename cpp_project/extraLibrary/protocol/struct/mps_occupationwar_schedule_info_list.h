#pragma once
#include <vector>
#include <string>
#include "mps_occupationwar_schedule_info.h"

namespace mir3d
{
	class mps_occupationwar_schedule_info_list 
	{
	public:
		std::vector<mps_occupationwar_schedule_info> list{};

	public:
		mps_occupationwar_schedule_info_list()
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
