﻿#pragma once
#include <vector>
#include <string>
#include "mps_db_buff.h"

namespace mir3d
{
	class mps_list_db_buff 
	{
	public:
		std::vector<mps_db_buff> info{};

	public:
		mps_list_db_buff()
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