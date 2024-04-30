#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_refinery_exchange_limit_check_cs : public WebBasePacket 	// 제련소 교환횟수 조건체크
	{
	public:
		int64_t auid{};

	public:
		mweb_refinery_exchange_limit_check_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_refinery_exchange_limit_check_sc : public WebBasePacket 	// 제련소 교환횟수 조건체크
	{
	public:
		int32_t daily_exchange_limit{};	// 일일 교환제한 횟수

	public:
		mweb_refinery_exchange_limit_check_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &daily_exchange_limit);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
