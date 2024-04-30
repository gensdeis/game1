#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_get_wemix_amount_cs : public BasePacket 	// 스왑 토큰에 위믹스 달러 수량 조회
	{
	public:
		mpe_token_type token_type{};	// 위믹스달러로 교환할 토큰
	public:
		std::string total_price{};

	public:
		mp_gate_get_wemix_amount_cs() : BasePacket(mpe_cmd::gate_get_wemix_amount_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeType(pBuffer, &total_price);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_get_wemix_amount_sc : public BasePacket 	// 스왑 토큰에 위믹스 달러 수량 조회
	{
	public:
		int32_t result{};
	public:
		std::string swap_amount{};
	public:
		mpe_token_type token_type{};	// 위믹스달러로 교환할 토큰

	public:
		mp_gate_get_wemix_amount_sc() : BasePacket(mpe_cmd::gate_get_wemix_amount_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &swap_amount);
			protocol::SerializeEnum(pBuffer, &token_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
