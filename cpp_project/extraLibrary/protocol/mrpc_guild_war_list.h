#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_war.h"

namespace mir3d
{
	class mrpc_guild_war_list_cs : public RpcPacket 	// 길드전쟁목록
	{
	public:
		int64_t key{};
	public:
		int64_t guid{};

	public:
		mrpc_guild_war_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_war_list_cs, tag)
		{
		}
		mrpc_guild_war_list_cs() : RpcPacket(mpe_rpc_cmd::guild_war_list_cs)
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

	class mrpc_guild_war_list_sc : public RpcPacket 	// 길드전쟁목록
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_guild_war> list_guild_war{};

	public:
		mrpc_guild_war_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_war_list_sc, tag)
		{
		}
		mrpc_guild_war_list_sc() : RpcPacket(mpe_rpc_cmd::guild_war_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &list_guild_war);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
