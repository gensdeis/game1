#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_contract_get_balance_to_wdoller_cs : public RpcPacket 	// wemixdoller 토큰 수량 조회
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		std::string user_address{};

	public:
		mrpc_gate_contract_get_balance_to_wdoller_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_contract_get_balance_to_wdoller_cs, tag)
		{
		}
		mrpc_gate_contract_get_balance_to_wdoller_cs() : RpcPacket(mpe_rpc_cmd::gate_contract_get_balance_to_wdoller_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &user_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_contract_get_balance_to_wdoller_sc : public RpcPacket 	// wemixdoller 토큰 수량 조회
	{
	public:
		int64_t key{};
	public:
		std::string wdoller{};	// wdoller 수량

	public:
		mrpc_gate_contract_get_balance_to_wdoller_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_contract_get_balance_to_wdoller_sc, tag)
		{
		}
		mrpc_gate_contract_get_balance_to_wdoller_sc() : RpcPacket(mpe_rpc_cmd::gate_contract_get_balance_to_wdoller_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &wdoller);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
