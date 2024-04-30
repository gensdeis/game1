#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_exchange_set_manual_latency_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t latency{};

	public:
		mrpc_gm_exchange_set_manual_latency_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_exchange_set_manual_latency_cs, tag)
		{
		}
		mrpc_gm_exchange_set_manual_latency_cs() : RpcPacket(mpe_rpc_cmd::gm_exchange_set_manual_latency_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &latency);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_exchange_set_manual_latency_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t latency{};

	public:
		mrpc_gm_exchange_set_manual_latency_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_exchange_set_manual_latency_sc, tag)
		{
		}
		mrpc_gm_exchange_set_manual_latency_sc() : RpcPacket(mpe_rpc_cmd::gm_exchange_set_manual_latency_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &latency);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
