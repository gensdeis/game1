#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods.h"
#include "struct/mps_guild_storage_treasure_auction.h"
#include "struct/mps_update_goods.h"

namespace mir3d
{
	class mrpc_guild_storage_treasure_request_cs : public RpcPacket 	// 문파 보물 창고 입찰
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int64_t auid{};
	public:
		int64_t auction_uid{};
	public:
		int32_t my_request_price{};
	public:
		std::vector<mps_update_goods> my_goods_info{};

	public:
		mrpc_guild_storage_treasure_request_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_treasure_request_cs, tag)
		{
		}
		mrpc_guild_storage_treasure_request_cs() : RpcPacket(mpe_rpc_cmd::guild_storage_treasure_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &auction_uid);
			protocol::SerializeType(pBuffer, &my_request_price);
			protocol::SerializeType(pBuffer, &my_goods_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_storage_treasure_request_sc : public RpcPacket 	// 문파 보물 창고 입찰
	{
	public:
		int64_t cuid{};
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
		std::vector<mps_update_goods> my_goods_info{};
	public:
		int32_t current_request_count{};

	public:
		mrpc_guild_storage_treasure_request_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_treasure_request_sc, tag)
		{
		}
		mrpc_guild_storage_treasure_request_sc() : RpcPacket(mpe_rpc_cmd::guild_storage_treasure_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_auction);
			if (true == flag_auction)
			{
				if (nullptr != p_auction)
					protocol::SerializeType(pBuffer, p_auction);
				else
					protocol::SerializeType(pBuffer, &auction);
			}
			protocol::SerializeType(pBuffer, &my_goods_info);
			protocol::SerializeType(pBuffer, &current_request_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
