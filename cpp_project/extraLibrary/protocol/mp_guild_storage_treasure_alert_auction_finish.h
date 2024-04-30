#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_storage_treasure_auction.h"

namespace mir3d
{
	class mp_guild_storage_treasure_alert_auction_finish_cs : public BasePacket 	// 문파 보물 창고 경매 종료 알림
	{

	public:
		mp_guild_storage_treasure_alert_auction_finish_cs() : BasePacket(mpe_cmd::guild_storage_treasure_alert_auction_finish_cs)
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

	class mp_guild_storage_treasure_alert_auction_finish_sc : public BasePacket 	// 문파 보물 창고 경매 종료 알림
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
		bool top_request{};

	public:
		mp_guild_storage_treasure_alert_auction_finish_sc() : BasePacket(mpe_cmd::guild_storage_treasure_alert_auction_finish_sc)
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
			protocol::SerializeType(pBuffer, &top_request);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
