#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_ally_info.h"

namespace mir3d
{
	class mrpc_guild_ally_list_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t my_guid{};	// 내문파 UID

	public:
		mrpc_guild_ally_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_ally_list_cs, tag)
		{
		}
		mrpc_guild_ally_list_cs() : RpcPacket(mpe_rpc_cmd::guild_ally_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &my_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_ally_list_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_guild_ally_info> ally_list{};	// "동맹문파목록"

	public:
		mrpc_guild_ally_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_ally_list_sc, tag)
		{
		}
		mrpc_guild_ally_list_sc() : RpcPacket(mpe_rpc_cmd::guild_ally_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &ally_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
