#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_contract_get_balance_cs : public RpcPacket 	// 토큰 수량 조회
	{
	public:
		int64_t key{};
	public:
		std::string user_address{};

	public:
		mrpc_gate_contract_get_balance_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_contract_get_balance_cs, tag)
		{
		}
		mrpc_gate_contract_get_balance_cs() : RpcPacket(mpe_rpc_cmd::gate_contract_get_balance_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &user_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_contract_get_balance_sc : public RpcPacket 	// 토큰 수량 조회
	{
	public:
		int64_t key{};
	public:
		std::string drone{};	// drone 수량
	public:
		std::string hydra{};	// hydra 수량
	public:
		std::string dogma{};	// dogma 수량

	public:
		mrpc_gate_contract_get_balance_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_contract_get_balance_sc, tag)
		{
		}
		mrpc_gate_contract_get_balance_sc() : RpcPacket(mpe_rpc_cmd::gate_contract_get_balance_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &drone);
			protocol::SerializeType(pBuffer, &hydra);
			protocol::SerializeType(pBuffer, &dogma);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
