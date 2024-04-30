#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_storage_history.h"

namespace mir3d
{
	class mrpc_gate_guild_storage_history_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t guid{};
	public:
		int32_t history_type{};

	public:
		mrpc_gate_guild_storage_history_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_guild_storage_history_cs, tag)
		{
		}
		mrpc_gate_guild_storage_history_cs() : RpcPacket(mpe_rpc_cmd::gate_guild_storage_history_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &history_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_guild_storage_history_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t result{};
	public:
		std::vector<mps_guild_storage_history> history_list{};

	public:
		mrpc_gate_guild_storage_history_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_guild_storage_history_sc, tag)
		{
		}
		mrpc_gate_guild_storage_history_sc() : RpcPacket(mpe_rpc_cmd::gate_guild_storage_history_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &history_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
