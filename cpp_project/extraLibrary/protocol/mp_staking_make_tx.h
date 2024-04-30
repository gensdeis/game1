#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_staking_make_tx_cs : public BasePacket 	// 스테이킹 트랜잭션 생성
	{
	public:
		mpe_token_type token_type{};	// 스테이킹 타입 (1: 드론, 2:하이드라)
	public:
		std::string user_wallet{};	// 유저 지갑 주소
	public:
		std::string amount{};	// 스테이킹 수량

	public:
		mp_staking_make_tx_cs() : BasePacket(mpe_cmd::staking_make_tx_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeType(pBuffer, &user_wallet);
			protocol::SerializeType(pBuffer, &amount);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_staking_make_tx_sc : public BasePacket 	// 스테이킹 트랜잭션 생성
	{
	public:
		mpe_error result{};
	public:
		std::string hash{};	// 해시값

	public:
		mp_staking_make_tx_sc() : BasePacket(mpe_cmd::staking_make_tx_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &hash);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
