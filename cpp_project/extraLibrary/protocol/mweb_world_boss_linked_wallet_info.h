﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_world_boss_linked_wallet_info_cs : public WebBasePacket 
	{
	public:
		int64_t auid{};	// 계정 아이디
	public:
		mpe_governance_contents_type contents_type{};	// 거버넌스 콘텐츠 타입(0:없음 1:보스 2:비곡점령전 3:공성전)
	public:
		std::string user_wallet{};	// 유저 지갑 주소
	public:
		int64_t cuid{};	// 캐릭터 아이디

	public:
		mweb_world_boss_linked_wallet_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeEnum(pBuffer, &contents_type);
			protocol::SerializeType(pBuffer, &user_wallet);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_world_boss_linked_wallet_info_sc : public WebBasePacket 
	{
	public:
		int32_t left_unstaking_time{};	// 남은 unstaking 가능시간 (UTC+0기준)
	public:
		int32_t unstaking_delay{};	// unstaking 대기시간 (UTC+0기준)
	public:
		std::string dogma_amount{};	// 나의 도그마보유량
	public:
		std::string staking_amount{};	// 나의 스테이킹량
	public:
		mpe_governance_contents_type contents_type{};	// 거버넌스 콘텐츠 타입(0:없음 1:보스 2:비곡점령전 3:공성전)

	public:
		mweb_world_boss_linked_wallet_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &left_unstaking_time);
			protocol::SerializeType(pBuffer, &unstaking_delay);
			protocol::SerializeType(pBuffer, &dogma_amount);
			protocol::SerializeType(pBuffer, &staking_amount);
			protocol::SerializeEnum(pBuffer, &contents_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
