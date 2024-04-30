﻿#pragma once
#include <vector>
#include <string>
#include "mps_item.h"

namespace mir3d
{
	class mps_guild_storage_share_request_get_item 
	{
	public:
		int64_t request_uid{};
	public:
		int64_t request_cuid{};
	private:
		bool flag_item = false;
		mps_item item;
		mps_item* p_item = nullptr;
	public:
		bool has_item() const
		{
			return flag_item;
		}
		mps_item* alloc_item()
		{
			flag_item = true;
			return &item;
		}
		const mps_item* get_item() const
		{
			if (true == flag_item)
			{
				if (nullptr == p_item)
				{
					return &item;
				}
				return p_item;
			}
			return nullptr;
		}
		void set_item(mps_item* in_item)
		{
			if (nullptr == p_item)
			{
				p_item = in_item;
				flag_item = true;
			}
		}
	public:
		int32_t request_count{};
	public:
		int64_t expire_time{};

	public:
		mps_guild_storage_share_request_get_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &request_uid);
			protocol::SerializeType(pBuffer, &request_cuid);
			protocol::SerializeType(pBuffer, &flag_item);
			if (true == flag_item)
			{
				if (nullptr != p_item)
					protocol::SerializeType(pBuffer, p_item);
				else
					protocol::SerializeType(pBuffer, &item);
			}
			protocol::SerializeType(pBuffer, &request_count);
			protocol::SerializeType(pBuffer, &expire_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
