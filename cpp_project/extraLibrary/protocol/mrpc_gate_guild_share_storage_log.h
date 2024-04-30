#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_share_storage_log.h"

namespace mir3d
{
	class mrpc_gate_guild_share_storage_log_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t guid{};
	public:
		int64_t last_time{};

	public:
		mrpc_gate_guild_share_storage_log_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_guild_share_storage_log_cs, tag)
		{
		}
		mrpc_gate_guild_share_storage_log_cs() : RpcPacket(mpe_rpc_cmd::gate_guild_share_storage_log_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &last_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_guild_share_storage_log_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_guild_share_storage_log> log_list{};
	public:
		int64_t last_time{};

	public:
		mrpc_gate_guild_share_storage_log_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_guild_share_storage_log_sc, tag)
		{
		}
		mrpc_gate_guild_share_storage_log_sc() : RpcPacket(mpe_rpc_cmd::gate_guild_share_storage_log_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &log_list);
			protocol::SerializeType(pBuffer, &last_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
