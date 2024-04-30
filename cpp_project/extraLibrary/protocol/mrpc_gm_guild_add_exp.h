#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_guild_add_exp_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t exp{};

	public:
		mrpc_gm_guild_add_exp_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_guild_add_exp_cs, tag)
		{
		}
		mrpc_gm_guild_add_exp_cs() : RpcPacket(mpe_rpc_cmd::gm_guild_add_exp_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &exp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_guild_add_exp_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t level{};
	public:
		int32_t exp{};

	public:
		mrpc_gm_guild_add_exp_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_guild_add_exp_sc, tag)
		{
		}
		mrpc_gm_guild_add_exp_sc() : RpcPacket(mpe_rpc_cmd::gm_guild_add_exp_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &exp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
