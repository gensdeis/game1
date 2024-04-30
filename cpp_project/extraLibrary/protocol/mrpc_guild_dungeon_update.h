#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_dungeon_update_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int64_t indun_uid{};
	public:
		int32_t tid{};
	public:
		int32_t dungeon_monster_total_hp{};	// 몬스터총hp
	public:
		int64_t indun_expire_time{};

	public:
		mrpc_guild_dungeon_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_dungeon_update_cs, tag)
		{
		}
		mrpc_guild_dungeon_update_cs() : RpcPacket(mpe_rpc_cmd::guild_dungeon_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &dungeon_monster_total_hp);
			protocol::SerializeType(pBuffer, &indun_expire_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_dungeon_update_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_guild_dungeon_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_dungeon_update_sc, tag)
		{
		}
		mrpc_guild_dungeon_update_sc() : RpcPacket(mpe_rpc_cmd::guild_dungeon_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
