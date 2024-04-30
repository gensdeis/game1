#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_contract_get_limit_cs : public WebBasePacket 	// 가능 수량 조회
	{
	public:
		int64_t auid{};
	public:
		std::string user_address{};

	public:
		mweb_contract_get_limit_cs() : WebBasePacket()
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

	class mweb_contract_get_limit_sc : public WebBasePacket 	// 가능 수량 조회
	{
	public:
		std::string drone_amount{};	// 드론 현재 발행량
	public:
		std::string user_amount{};	// 유저 현재 발행량

	public:
		mweb_contract_get_limit_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &drone_amount);
			protocol::SerializeType(pBuffer, &user_amount);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
