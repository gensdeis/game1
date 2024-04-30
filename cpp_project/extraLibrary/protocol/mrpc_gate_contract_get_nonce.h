#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_contract_get_nonce_cs : public RpcPacket 	// nonce값 조회
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		std::string user_address{};
	public:
		mpe_token_type token_type{};	// 토큰 타입 (1: 드론, 2:하이드라)
	public:
		mpe_contract_type contract_type{};	// 컨트랙트 타입

	public:
		mrpc_gate_contract_get_nonce_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_contract_get_nonce_cs, tag)
		{
		}
		mrpc_gate_contract_get_nonce_cs() : RpcPacket(mpe_rpc_cmd::gate_contract_get_nonce_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &user_address);
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeEnum(pBuffer, &contract_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_contract_get_nonce_sc : public RpcPacket 	// nonce값 조회
	{
	public:
		int64_t key{};
	public:
		std::string nonce{};	// nonce 값

	public:
		mrpc_gate_contract_get_nonce_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_contract_get_nonce_sc, tag)
		{
		}
		mrpc_gate_contract_get_nonce_sc() : RpcPacket(mpe_rpc_cmd::gate_contract_get_nonce_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &nonce);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
