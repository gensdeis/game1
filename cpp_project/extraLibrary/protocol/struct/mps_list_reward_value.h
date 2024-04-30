#pragma once
#include <vector>
#include <string>
#include "mps_reward_value.h"

namespace mir3d
{
	class mps_list_reward_value 
	{
	public:
		std::vector<mps_reward_value> info{};

	public:
		mps_list_reward_value()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
