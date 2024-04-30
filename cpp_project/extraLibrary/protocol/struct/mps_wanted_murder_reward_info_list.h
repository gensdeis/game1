﻿#pragma once
#include <vector>
#include <string>
#include "mps_wanted_murder_reward_info.h"

namespace mir3d
{
	class mps_wanted_murder_reward_info_list 
	{
	public:
		std::vector<mps_wanted_murder_reward_info> info{};

	public:
		mps_wanted_murder_reward_info_list()
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