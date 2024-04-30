#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_claim_send_tx_cs : public BasePacket 	// 스테이킹 보상 청구 트랜잭션 전송
	{
	public:
		std::string signature{};	// 사인값

	public:
		mp_claim_send_tx_cs() : BasePacket(mpe_cmd::claim_send_tx_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &signature);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_claim_send_tx_sc : public BasePacket 	// 스테이킹 보상 청구 트랜잭션 전송
	{
	public:
		mpe_error result{};

	public:
		mp_claim_send_tx_sc() : BasePacket(mpe_cmd::claim_send_tx_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
