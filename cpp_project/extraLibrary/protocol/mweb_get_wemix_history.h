#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_wemix_shop_history.h"

namespace mir3d
{
	class mweb_get_wemix_history_cs : public WebBasePacket 	// 위믹스 상점 내역 조회
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mweb_get_wemix_history_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_get_wemix_history_sc : public WebBasePacket 	// 위믹스 상점 내역 조회
	{
	public:
		std::vector<mps_wemix_shop_history> shop_history{};

	public:
		mweb_get_wemix_history_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &shop_history);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
