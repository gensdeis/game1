﻿#pragma once
#include <vector>
#include <string>
#include "mps_global_exchange_sell_item.h"

namespace mir3d
{
	class mps_global_exchange_sell_item_type 
	{
	public:
		int32_t type{};	// exchange_type
	public:
		std::vector<mps_global_exchange_sell_item> list{};

	public:
		mps_global_exchange_sell_item_type()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
