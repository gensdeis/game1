#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_log.h"

namespace mir3d
{
	class mrpc_gate_castle_town_log_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t guid{};

	public:
		mrpc_gate_castle_town_log_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_castle_town_log_cs, tag)
		{
		}
		mrpc_gate_castle_town_log_cs() : RpcPacket(mpe_rpc_cmd::gate_castle_town_log_cs)
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

	class mrpc_gate_castle_town_log_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_castle_town_log> castle_town_log_list{};

	public:
		mrpc_gate_castle_town_log_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_castle_town_log_sc, tag)
		{
		}
		mrpc_gate_castle_town_log_sc() : RpcPacket(mpe_rpc_cmd::gate_castle_town_log_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &castle_town_log_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
