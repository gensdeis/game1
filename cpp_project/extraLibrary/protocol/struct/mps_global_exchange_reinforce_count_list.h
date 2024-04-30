#pragma once
#include <vector>
#include <string>
#include "mps_global_exchange_reinforce_count.h"

namespace mir3d
{
	class mps_global_exchange_reinforce_count_list 
	{
	public:
		std::vector<mps_global_exchange_reinforce_count> list{};

	public:
		mps_global_exchange_reinforce_count_list()
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
