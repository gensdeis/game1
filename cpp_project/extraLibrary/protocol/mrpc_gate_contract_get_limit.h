#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_contract_get_limit_cs : public RpcPacket 	// 가능 수량 조회
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		std::string user_address{};

	public:
		mrpc_gate_contract_get_limit_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_contract_get_limit_cs, tag)
		{
		}
		mrpc_gate_contract_get_limit_cs() : RpcPacket(mpe_rpc_cmd::gate_contract_get_limit_cs)
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

	class mrpc_gate_contract_get_limit_sc : public RpcPacket 	// 가능 수량 조회
	{
	public:
		int64_t key{};
	public:
		std::string drone_amount{};	// 드론 현재 발행량
	public:
		std::string user_amount{};	// 유저 현재 발행량

	public:
		mrpc_gate_contract_get_limit_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_contract_get_limit_sc, tag)
		{
		}
		mrpc_gate_contract_get_limit_sc() : RpcPacket(mpe_rpc_cmd::gate_contract_get_limit_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &drone_amount);
			protocol::SerializeType(pBuffer, &user_amount);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
