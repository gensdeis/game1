#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_cart_item.h"

namespace mir3d
{
	class mweb_api_character_cart_get_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};

	public:
		mweb_api_character_cart_get_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_character_cart_get_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	public:
		std::vector<mps_cart_item> list{};

	public:
		mweb_api_character_cart_get_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
