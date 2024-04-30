#pragma once
#include <vector>
#include <string>
#include "mps_item.h"
#include "mps_guild_storage_treasure_request.h"

namespace mir3d
{
	class mps_guild_storage_treasure_auction 
	{
	public:
		int64_t auction_uid{};
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
		int64_t expire_time{};
	public:
		std::vector<int64_t> list_request_member{};
	public:
		int32_t final_request_member_count{};
	private:
		bool flag_top_request = false;
		mps_guild_storage_treasure_request top_request;
		mps_guild_storage_treasure_request* p_top_request = nullptr;
	public:
		bool has_top_request() const
		{
			return flag_top_request;
		}
		mps_guild_storage_treasure_request* alloc_top_request()
		{
			flag_top_request = true;
			return &top_request;
		}
		const mps_guild_storage_treasure_request* get_top_request() const
		{
			if (true == flag_top_request)
			{
				if (nullptr == p_top_request)
				{
					return &top_request;
				}
				return p_top_request;
			}
			return nullptr;
		}
		void set_top_request(mps_guild_storage_treasure_request* in_top_request)
		{
			if (nullptr == p_top_request)
			{
				p_top_request = in_top_request;
				flag_top_request = true;
			}
		}
	public:
		bool finished{};

	public:
		mps_guild_storage_treasure_auction()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &auction_uid);
			protocol::SerializeType(pBuffer, &flag_item);
			if (true == flag_item)
			{
				if (nullptr != p_item)
					protocol::SerializeType(pBuffer, p_item);
				else
					protocol::SerializeType(pBuffer, &item);
			}
			protocol::SerializeType(pBuffer, &expire_time);
			protocol::SerializeType(pBuffer, &list_request_member);
			protocol::SerializeType(pBuffer, &final_request_member_count);
			protocol::SerializeType(pBuffer, &flag_top_request);
			if (true == flag_top_request)
			{
				if (nullptr != p_top_request)
					protocol::SerializeType(pBuffer, p_top_request);
				else
					protocol::SerializeType(pBuffer, &top_request);
			}
			protocol::SerializeType(pBuffer, &finished);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
