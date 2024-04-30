#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_contract_token_allowance_cs : public RpcPacket 	// 토큰 approve 수량 조회
	{
	public:
		int64_t key{};
	public:
		std::string user_wallet{};	// 유저 지갑 주소
	public:
		mpe_token_type token_type{};	// 토큰 타입 (1: 드론, 2:하이드라)
	public:
		mpe_contract_type contract_type{};	// 컨트랙트 타입

	public:
		mrpc_gate_contract_token_allowance_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_contract_token_allowance_cs, tag)
		{
		}
		mrpc_gate_contract_token_allowance_cs() : RpcPacket(mpe_rpc_cmd::gate_contract_token_allowance_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &user_wallet);
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeEnum(pBuffer, &contract_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_contract_token_allowance_sc : public RpcPacket 	// 토큰 approve 수량 조회
	{
	public:
		int64_t key{};
	public:
		std::string amount{};	// approve 수량
	public:
		mpe_token_type token_type{};	// 토큰 타입 (1: 드론, 2:하이드라)
	public:
		mpe_contract_type contract_type{};	// 컨트랙트 타입

	public:
		mrpc_gate_contract_token_allowance_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_contract_token_allowance_sc, tag)
		{
		}
		mrpc_gate_contract_token_allowance_sc() : RpcPacket(mpe_rpc_cmd::gate_contract_token_allowance_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &amount);
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeEnum(pBuffer, &contract_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
