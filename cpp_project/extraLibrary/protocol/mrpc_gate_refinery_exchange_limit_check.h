#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_refinery_exchange_limit_check_cs : public RpcPacket 	// 제련소 교환횟수 조건체크
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};

	public:
		mrpc_gate_refinery_exchange_limit_check_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_refinery_exchange_limit_check_cs, tag)
		{
		}
		mrpc_gate_refinery_exchange_limit_check_cs() : RpcPacket(mpe_rpc_cmd::gate_refinery_exchange_limit_check_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_refinery_exchange_limit_check_sc : public RpcPacket 	// 제련소 교환횟수 조건체크
	{
	public:
		int64_t key{};
	public:
		int32_t daily_exchange_limit{};	// 일일 교환제한 횟수

	public:
		mrpc_gate_refinery_exchange_limit_check_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_refinery_exchange_limit_check_sc, tag)
		{
		}
		mrpc_gate_refinery_exchange_limit_check_sc() : RpcPacket(mpe_rpc_cmd::gate_refinery_exchange_limit_check_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &daily_exchange_limit);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
