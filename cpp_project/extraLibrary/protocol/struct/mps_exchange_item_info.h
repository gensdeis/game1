﻿#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_exchange_item_info 
	{
	public:
		int64_t euid{};
	public:
		int64_t auid{};
	public:
		int32_t price{};
	public:
		int32_t count{};
	public:
		int32_t reinforce{};
	public:
		int32_t expire{};
	public:
		int32_t gid{};
	public:
		int32_t awaken_step{};

	public:
		mps_exchange_item_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &price);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &reinforce);
			protocol::SerializeType(pBuffer, &expire);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &awaken_step);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}