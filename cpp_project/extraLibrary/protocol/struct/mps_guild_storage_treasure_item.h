#pragma once
#include <vector>
#include <string>
#include "mps_guild_storage_treasure_auction.h"

namespace mir3d
{
	class mps_guild_storage_treasure_item 
	{
	private:
		bool flag_auction = false;
		mps_guild_storage_treasure_auction auction;
		mps_guild_storage_treasure_auction* p_auction = nullptr;
	public:
		bool has_auction() const
		{
			return flag_auction;
		}
		mps_guild_storage_treasure_auction* alloc_auction()
		{
			flag_auction = true;
			return &auction;
		}
		const mps_guild_storage_treasure_auction* get_auction() const
		{
			if (true == flag_auction)
			{
				if (nullptr == p_auction)
				{
					return &auction;
				}
				return p_auction;
			}
			return nullptr;
		}
		void set_auction(mps_guild_storage_treasure_auction* in_auction)
		{
			if (nullptr == p_auction)
			{
				p_auction = in_auction;
				flag_auction = true;
			}
		}

	public:
		mps_guild_storage_treasure_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &flag_auction);
			if (true == flag_auction)
			{
				if (nullptr != p_auction)
					protocol::SerializeType(pBuffer, p_auction);
				else
					protocol::SerializeType(pBuffer, &auction);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
