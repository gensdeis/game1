﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_purchase_info.h"

namespace mir3d
{
	class mp_gate_wemix_pay_start_cs : public BasePacket 	// 위믹스 상점 트랜잭션 hash 발급
	{
	public:
		std::string player_key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string user_address{};	// 유저 월렛 주소
	public:
		std::string user_agent{};
	public:
		std::vector<mps_purchase_info> purchase_info{};
	public:
		std::string total_price{};
	public:
		std::string ip_address{};
	public:
		mpe_token_type token_type{};	// 토큰 타입이 위믹스 달러가 아니면 전부 스왑 결제

	public:
		mp_gate_wemix_pay_start_cs() : BasePacket(mpe_cmd::gate_wemix_pay_start_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &player_key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &user_address);
			protocol::SerializeType(pBuffer, &user_agent);
			protocol::SerializeType(pBuffer, &purchase_info);
			protocol::SerializeType(pBuffer, &total_price);
			protocol::SerializeType(pBuffer, &ip_address);
			protocol::SerializeEnum(pBuffer, &token_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_wemix_pay_start_sc : public BasePacket 	// 위믹스 상점 트랜잭션 hash 발급
	{
	public:
		int32_t code{};
	public:
		int32_t result{};
	public:
		std::string hash{};	// hash값 전달
	public:
		mpe_token_type token_type{};	// 토큰 타입 (1: 드론, 2:하이드라)
	public:
		mpe_contract_type contract_type{};	// 컨트랙트 타입
	public:
		std::string pay_id{};	// pay id

	public:
		mp_gate_wemix_pay_start_sc() : BasePacket(mpe_cmd::gate_wemix_pay_start_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &code);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &hash);
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeEnum(pBuffer, &contract_type);
			protocol::SerializeType(pBuffer, &pay_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}