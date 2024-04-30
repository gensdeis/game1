#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_cash_shop_buy_count.h"
#include "struct/mps_cash_shop_buy_count.h"

namespace mir3d
{
	class mweb_api_character_cashshop_buy_select_cs : public WebBasePacket 
	{
	public:
		int64_t auid{};

	public:
		mweb_api_character_cashshop_buy_select_cs() : WebBasePacket()
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

	class mweb_api_character_cashshop_buy_select_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	public:
		std::vector<mps_cash_shop_buy_count> list_account{};
	public:
		std::vector<mps_cash_shop_buy_count> list_server_character{};

	public:
		mweb_api_character_cashshop_buy_select_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &list_account);
			protocol::SerializeType(pBuffer, &list_server_character);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
