﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_purchase_info.h"

namespace mir3d
{
	class mweb_wemix_pay_end_cs : public WebBasePacket 	// 위믹스 상점 트랜잭션 마무리
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
		std::string signature{};
	public:
		mpe_token_type token_type{};	// 토큰 타입이 위믹스 달러가 아니면 전부 스왑 결제
	public:
		std::string pay_id{};	// pay id

	public:
		mweb_wemix_pay_end_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &player_key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &user_address);
			protocol::SerializeType(pBuffer, &user_agent);
			protocol::SerializeType(pBuffer, &purchase_info);
			protocol::SerializeType(pBuffer, &total_price);
			protocol::SerializeType(pBuffer, &ip_address);
			protocol::SerializeType(pBuffer, &signature);
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeType(pBuffer, &pay_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_wemix_pay_end_sc : public WebBasePacket 	// 위믹스 상점 트랜잭션 마무리
	{
	public:
		int32_t result{};
	public:
		int32_t code{};

	public:
		mweb_wemix_pay_end_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &code);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
