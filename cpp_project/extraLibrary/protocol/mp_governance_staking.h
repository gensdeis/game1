﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_governance_staking_cs : public BasePacket 	// 선택된 서버에 코인 스테이킹
	{
	public:
		int32_t gid{};	// 내가 속한 서버 아이디
	public:
		int64_t auid{};	// 계정 아이디
	public:
		std::string amount{};	// 스테이킹량
	public:
		std::string contract{};	// contract address 값
	public:
		std::string user{};	// 유저 wallet id
	public:
		std::string signature{};	// 유저 사인값
	public:
		std::string nonce{};	// 컨트랙트 서버에서 조회한 nonce 값
	public:
		std::string column{};	// 액션에 대한 bytes32 값
	public:
		int32_t agenda_id{};	// Contract서버에서 관리하는 월드아이디
	public:
		int32_t sector_id{};	// Contract서버에서 관리하는 서버아이디
	public:
		mpe_governance_contents_type contents_type{};	// 거버넌스 콘텐츠 타입(0:없음 1:보스 2:비곡점령전 3:공성전)

	public:
		mp_governance_staking_cs() : BasePacket(mpe_cmd::governance_staking_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &amount);
			protocol::SerializeType(pBuffer, &contract);
			protocol::SerializeType(pBuffer, &user);
			protocol::SerializeType(pBuffer, &signature);
			protocol::SerializeType(pBuffer, &nonce);
			protocol::SerializeType(pBuffer, &column);
			protocol::SerializeType(pBuffer, &agenda_id);
			protocol::SerializeType(pBuffer, &sector_id);
			protocol::SerializeEnum(pBuffer, &contents_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_governance_staking_sc : public BasePacket 	// 선택된 서버에 코인 스테이킹
	{
	public:
		mpe_error result{};	// 응답결과
	public:
		int32_t gid{};	// 서버 아이디
	public:
		std::string amount{};	// 스테이킹량
	public:
		mpe_governance_contents_type contents_type{};	// 거버넌스 콘텐츠 타입(0:없음 1:보스 2:비곡점령전 3:공성전)

	public:
		mp_governance_staking_sc() : BasePacket(mpe_cmd::governance_staking_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &amount);
			protocol::SerializeEnum(pBuffer, &contents_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
