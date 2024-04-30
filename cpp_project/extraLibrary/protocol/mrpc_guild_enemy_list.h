#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_enemy_list_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t guid{};

	public:
		mrpc_guild_enemy_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_enemy_list_cs, tag)
		{
		}
		mrpc_guild_enemy_list_cs() : RpcPacket(mpe_rpc_cmd::guild_enemy_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_enemy_list_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<int64_t> list_enemy_guid{};
	public:
		std::vector<uint8_t> list_enemy_penalty{};

	public:
		mrpc_guild_enemy_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_enemy_list_sc, tag)
		{
		}
		mrpc_guild_enemy_list_sc() : RpcPacket(mpe_rpc_cmd::guild_enemy_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &list_enemy_guid);
			protocol::SerializeType(pBuffer, &list_enemy_penalty);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
