#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_pr_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};

	public:
		mrpc_guild_pr_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_pr_cs, tag)
		{
		}
		mrpc_guild_pr_cs() : RpcPacket(mpe_rpc_cmd::guild_pr_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_pr_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		bool result{};

	public:
		mrpc_guild_pr_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_pr_sc, tag)
		{
		}
		mrpc_guild_pr_sc() : RpcPacket(mpe_rpc_cmd::guild_pr_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
