#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_dungeon_member_damage_cs : public RpcPacket 	// 길드던전피해량저장
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t damage{};
	public:
		int32_t kill_monster_count{};

	public:
		mrpc_guild_dungeon_member_damage_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_dungeon_member_damage_cs, tag)
		{
		}
		mrpc_guild_dungeon_member_damage_cs() : RpcPacket(mpe_rpc_cmd::guild_dungeon_member_damage_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &damage);
			protocol::SerializeType(pBuffer, &kill_monster_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_dungeon_member_damage_sc : public RpcPacket 	// 길드던전피해량저장
	{
	public:
		int64_t key{};

	public:
		mrpc_guild_dungeon_member_damage_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_dungeon_member_damage_sc, tag)
		{
		}
		mrpc_guild_dungeon_member_damage_sc() : RpcPacket(mpe_rpc_cmd::guild_dungeon_member_damage_sc)
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
