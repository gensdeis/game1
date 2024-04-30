#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_get_wemix_amount_cs : public WebBasePacket 	// 스왑 토큰에 위믹스 달러 수량 조회
	{
	public:
		mpe_token_type token_type{};	// 위믹스달러로 교환할 토큰
	public:
		std::string total_price{};

	public:
		mweb_get_wemix_amount_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeType(pBuffer, &total_price);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_get_wemix_amount_sc : public WebBasePacket 	// 스왑 토큰에 위믹스 달러 수량 조회
	{
	public:
		int32_t result{};
	public:
		std::string swap_amount{};
	public:
		mpe_token_type token_type{};	// 위믹스달러로 교환할 토큰

	public:
		mweb_get_wemix_amount_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &swap_amount);
			protocol::SerializeEnum(pBuffer, &token_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
