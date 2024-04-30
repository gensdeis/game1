#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_storage_treasure_auction.h"
#include "struct/mps_update_goods.h"

namespace mir3d
{
	class mp_guild_storage_treasure_alert_lost_top_request_cs : public BasePacket 	// 문파 보물 창고 유찰 알림
	{

	public:
		mp_guild_storage_treasure_alert_lost_top_request_cs() : BasePacket(mpe_cmd::guild_storage_treasure_alert_lost_top_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_storage_treasure_alert_lost_top_request_sc : public BasePacket 	// 문파 보물 창고 유찰 알림
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
	private:
		bool flag_return_guild_point = false;
		mps_update_goods return_guild_point;
		mps_update_goods* p_return_guild_point = nullptr;
	public:
		bool has_return_guild_point() const
		{
			return flag_return_guild_point;
		}
		mps_update_goods* alloc_return_guild_point()
		{
			flag_return_guild_point = true;
			return &return_guild_point;
		}
		const mps_update_goods* get_return_guild_point() const
		{
			if (true == flag_return_guild_point)
			{
				if (nullptr == p_return_guild_point)
				{
					return &return_guild_point;
				}
				return p_return_guild_point;
			}
			return nullptr;
		}
		void set_return_guild_point(mps_update_goods* in_return_guild_point)
		{
			if (nullptr == p_return_guild_point)
			{
				p_return_guild_point = in_return_guild_point;
				flag_return_guild_point = true;
			}
		}

	public:
		mp_guild_storage_treasure_alert_lost_top_request_sc() : BasePacket(mpe_cmd::guild_storage_treasure_alert_lost_top_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_auction);
			if (true == flag_auction)
			{
				if (nullptr != p_auction)
					protocol::SerializeType(pBuffer, p_auction);
				else
					protocol::SerializeType(pBuffer, &auction);
			}
			protocol::SerializeType(pBuffer, &flag_return_guild_point);
			if (true == flag_return_guild_point)
			{
				if (nullptr != p_return_guild_point)
					protocol::SerializeType(pBuffer, p_return_guild_point);
				else
					protocol::SerializeType(pBuffer, &return_guild_point);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
