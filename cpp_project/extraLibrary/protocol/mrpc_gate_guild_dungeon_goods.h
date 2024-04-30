#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_goods_info.h"
#include "struct/mps_item_id.h"

namespace mir3d
{
	class mrpc_gate_guild_dungeon_goods_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t tid{};
	public:
		int32_t open_count{};

	public:
		mrpc_gate_guild_dungeon_goods_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_guild_dungeon_goods_cs, tag)
		{
		}
		mrpc_gate_guild_dungeon_goods_cs() : RpcPacket(mpe_rpc_cmd::gate_guild_dungeon_goods_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &open_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_guild_dungeon_goods_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t result{};
	public:
		std::vector<mps_guild_goods_info> goods_info{};
	public:
		std::vector<mps_item_id> list_item{};
	public:
		int32_t open_count{};

	public:
		mrpc_gate_guild_dungeon_goods_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_guild_dungeon_goods_sc, tag)
		{
		}
		mrpc_gate_guild_dungeon_goods_sc() : RpcPacket(mpe_rpc_cmd::gate_guild_dungeon_goods_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &goods_info);
			protocol::SerializeType(pBuffer, &list_item);
			protocol::SerializeType(pBuffer, &open_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
