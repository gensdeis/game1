#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_pr_notify_cs : public RpcPacket 
	{

	public:
		mrpc_guild_pr_notify_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_pr_notify_cs, tag)
		{
		}
		mrpc_guild_pr_notify_cs() : RpcPacket(mpe_rpc_cmd::guild_pr_notify_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_pr_notify_sc : public RpcPacket 
	{
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		int32_t member_count{};
	public:
		int32_t max_member_count{};
	public:
		int32_t gid{};

	public:
		mrpc_guild_pr_notify_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_pr_notify_sc, tag)
		{
		}
		mrpc_guild_pr_notify_sc() : RpcPacket(mpe_rpc_cmd::guild_pr_notify_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &member_count);
			protocol::SerializeType(pBuffer, &max_member_count);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
