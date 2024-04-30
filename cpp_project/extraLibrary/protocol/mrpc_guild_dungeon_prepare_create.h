#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_dungeon_prepare_create_cs : public RpcPacket 
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
		std::vector<int32_t> list_item_id{};	// // 사용 id 목록

	public:
		mrpc_guild_dungeon_prepare_create_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_dungeon_prepare_create_cs, tag)
		{
		}
		mrpc_guild_dungeon_prepare_create_cs() : RpcPacket(mpe_rpc_cmd::guild_dungeon_prepare_create_cs)
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
			protocol::SerializeType(pBuffer, &list_item_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_dungeon_prepare_create_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t tid{};
	public:
		std::vector<int32_t> list_item_id{};	// // 사용 id 목록

	public:
		mrpc_guild_dungeon_prepare_create_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_dungeon_prepare_create_sc, tag)
		{
		}
		mrpc_guild_dungeon_prepare_create_sc() : RpcPacket(mpe_rpc_cmd::guild_dungeon_prepare_create_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &list_item_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
