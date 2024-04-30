#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_contract_get_balance_cs : public WebBasePacket 	// 토큰 수량 조회
	{
	public:
		int64_t auid{};
	public:
		std::string user_address{};

	public:
		mweb_contract_get_balance_cs() : WebBasePacket()
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

	class mweb_contract_get_balance_sc : public WebBasePacket 	// 토큰 수량 조회
	{
	public:
		std::string drone{};	// drone 수량
	public:
		std::string hydra{};	// hydra 수량
	public:
		std::string dogma{};	// dogma 수량

	public:
		mweb_contract_get_balance_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &drone);
			protocol::SerializeType(pBuffer, &hydra);
			protocol::SerializeType(pBuffer, &dogma);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
