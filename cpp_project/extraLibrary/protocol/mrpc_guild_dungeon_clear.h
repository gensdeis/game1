#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_guild_dungeon_reward.h"

namespace mir3d
{
	class mrpc_guild_dungeon_clear_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t guid{};
	public:
		int64_t indun_uid{};
	public:
		int32_t tid{};
	public:
		std::vector<mrpcs_guild_dungeon_reward> list_reward{};
	public:
		std::vector<int32_t> list_clear_reward_id{};

	public:
		mrpc_guild_dungeon_clear_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_dungeon_clear_cs, tag)
		{
		}
		mrpc_guild_dungeon_clear_cs() : RpcPacket(mpe_rpc_cmd::guild_dungeon_clear_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &list_reward);
			protocol::SerializeType(pBuffer, &list_clear_reward_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_dungeon_clear_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_guild_dungeon_clear_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_dungeon_clear_sc, tag)
		{
		}
		mrpc_guild_dungeon_clear_sc() : RpcPacket(mpe_rpc_cmd::guild_dungeon_clear_sc)
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
