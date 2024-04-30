#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_api_guild_notice_change_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t guid{};
	public:
		std::string notice{};

	public:
		mrpc_gm_api_guild_notice_change_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_api_guild_notice_change_cs, tag)
		{
		}
		mrpc_gm_api_guild_notice_change_cs() : RpcPacket(mpe_rpc_cmd::gm_api_guild_notice_change_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &notice);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_api_guild_notice_change_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gm_api_guild_notice_change_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_api_guild_notice_change_sc, tag)
		{
		}
		mrpc_gm_api_guild_notice_change_sc() : RpcPacket(mpe_rpc_cmd::gm_api_guild_notice_change_sc)
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
