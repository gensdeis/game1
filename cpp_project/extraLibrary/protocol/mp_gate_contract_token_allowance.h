#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_contract_token_allowance_cs : public BasePacket 	// 토큰 approve 수량 조회
	{
	public:
		std::string user_wallet{};	// 유저 지갑 주소
	public:
		mpe_token_type token_type{};	// 토큰 타입 (1: 드론, 2:하이드라)
	public:
		mpe_contract_type contract_type{};	// 컨트랙트 타입

	public:
		mp_gate_contract_token_allowance_cs() : BasePacket(mpe_cmd::gate_contract_token_allowance_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &user_wallet);
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeEnum(pBuffer, &contract_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_contract_token_allowance_sc : public BasePacket 	// 토큰 approve 수량 조회
	{
	public:
		mpe_error result{};
	public:
		std::string amount{};	// approve 수량
	public:
		mpe_token_type token_type{};	// 토큰 타입 (1: 드론, 2:하이드라)
	public:
		mpe_contract_type contract_type{};	// 컨트랙트 타입

	public:
		mp_gate_contract_token_allowance_sc() : BasePacket(mpe_cmd::gate_contract_token_allowance_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &amount);
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeEnum(pBuffer, &contract_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
