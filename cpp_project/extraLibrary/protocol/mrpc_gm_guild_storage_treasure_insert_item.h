#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_guild_storage_treasure_insert_item_cs : public RpcPacket 	// 문파 보물 창고 아이템 넣기 (test용)
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t item_tid{};
	public:
		int32_t add_minute{};

	public:
		mrpc_gm_guild_storage_treasure_insert_item_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_guild_storage_treasure_insert_item_cs, tag)
		{
		}
		mrpc_gm_guild_storage_treasure_insert_item_cs() : RpcPacket(mpe_rpc_cmd::gm_guild_storage_treasure_insert_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &item_tid);
			protocol::SerializeType(pBuffer, &add_minute);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_guild_storage_treasure_insert_item_sc : public RpcPacket 	// 문파 보물 창고 아이템 넣기 (test용)
	{
	public:
		int64_t cuid{};

	public:
		mrpc_gm_guild_storage_treasure_insert_item_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_guild_storage_treasure_insert_item_sc, tag)
		{
		}
		mrpc_gm_guild_storage_treasure_insert_item_sc() : RpcPacket(mpe_rpc_cmd::gm_guild_storage_treasure_insert_item_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
