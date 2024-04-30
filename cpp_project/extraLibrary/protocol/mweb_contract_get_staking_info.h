﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_contract_get_staking_info_cs : public WebBasePacket 	// 스테이킹 관련 정보 조회
	{
	public:
		int64_t auid{};
	public:
		std::string user_address{};

	public:
		mweb_contract_get_staking_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &user_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_contract_get_staking_info_sc : public WebBasePacket 	// 스테이킹 관련 정보 조회
	{
	public:
		std::string drone_staking{};	// 드론 스테이킹 수량
	public:
		std::string hydra_staking{};	// 하이드라 스테이킹 수량
	public:
		std::string drone_mp{};	// 드론 mp
	public:
		std::string hydra_mp{};	// 하이드라mp
	public:
		std::string drone_claim{};	// 드론 현재 보상받을 수량
	public:
		std::string hydra_claim{};	// 하이드라 현재 보상받을 수량
	public:
		std::string total_claim_drone{};	// 드론으로 현재까지 보상받은 총량
	public:
		std::string total_claim_hydra{};	// 하이드라로 현재까지 보상받은 총량
	public:
		std::string total_burn{};	// 현재까지 삭제된 수량
	public:
		std::string total_hydra{};	// 총 하이드라 스테이킹량
	public:
		std::string total_drone{};	// 총 드론 스테이킹량
	public:
		std::string drone_claim_cooltime{};	// 드론 클레임 쿨
	public:
		std::string hydra_claim_cooltime{};	// 하이드라 클레임 쿨
	public:
		std::string drone_staking_cooltime{};	// 드론 스테이킹 쿨
	public:
		std::string hydra_staking_cooltime{};	// 하이드라 스테이킹 쿨

	public:
		mweb_contract_get_staking_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &drone_staking);
			protocol::SerializeType(pBuffer, &hydra_staking);
			protocol::SerializeType(pBuffer, &drone_mp);
			protocol::SerializeType(pBuffer, &hydra_mp);
			protocol::SerializeType(pBuffer, &drone_claim);
			protocol::SerializeType(pBuffer, &hydra_claim);
			protocol::SerializeType(pBuffer, &total_claim_drone);
			protocol::SerializeType(pBuffer, &total_claim_hydra);
			protocol::SerializeType(pBuffer, &total_burn);
			protocol::SerializeType(pBuffer, &total_hydra);
			protocol::SerializeType(pBuffer, &total_drone);
			protocol::SerializeType(pBuffer, &drone_claim_cooltime);
			protocol::SerializeType(pBuffer, &hydra_claim_cooltime);
			protocol::SerializeType(pBuffer, &drone_staking_cooltime);
			protocol::SerializeType(pBuffer, &hydra_staking_cooltime);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}