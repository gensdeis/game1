#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_claim_make_tx_cs : public BasePacket 	// 스테이킹 보상 청구 트랜잭션 생성
	{
	public:
		std::string user_wallet{};	// 유저 지갑 주소

	public:
		mp_claim_make_tx_cs() : BasePacket(mpe_cmd::claim_make_tx_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &user_wallet);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_claim_make_tx_sc : public BasePacket 	// 스테이킹 보상 청구 트랜잭션 생성
	{
	public:
		mpe_error result{};
	public:
		std::string hash{};	// 해시값

	public:
		mp_claim_make_tx_sc() : BasePacket(mpe_cmd::claim_make_tx_sc)
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
