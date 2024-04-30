#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_contract_get_nonce_cs : public WebBasePacket 	// nonce값 조회
	{
	public:
		int64_t auid{};
	public:
		std::string user_address{};
	public:
		mpe_token_type token_type{};	// 토큰 타입 (1: 드론, 2:하이드라)
	public:
		mpe_contract_type contract_type{};	// 컨트랙트 타입

	public:
		mweb_contract_get_nonce_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &user_address);
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeEnum(pBuffer, &contract_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_contract_get_nonce_sc : public WebBasePacket 	// nonce값 조회
	{
	public:
		std::string nonce{};	// nonce 값

	public:
		mweb_contract_get_nonce_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nonce);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
