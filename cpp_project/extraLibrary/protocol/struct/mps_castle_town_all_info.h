﻿#pragma once
#include <vector>
#include <string>
#include "mps_castle_town_info.h"

namespace mir3d
{
	class mps_castle_town_all_info 
	{
	public:
		std::vector<mps_castle_town_info> info{};	// 장원 정보

	public:
		mps_castle_town_all_info()
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