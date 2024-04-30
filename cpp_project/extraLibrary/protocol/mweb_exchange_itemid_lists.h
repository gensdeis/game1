#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_exchange_item_info.h"

namespace mir3d
{
	class mweb_exchange_itemid_lists_cs : public WebBasePacket 
	{
	public:
		int32_t exchange_type{};
	public:
		int32_t class_type{};
	public:
		int32_t id{};
	public:
		int32_t page{};

	public:
		mweb_exchange_itemid_lists_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &exchange_type);
			protocol::SerializeType(pBuffer, &class_type);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &page);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_exchange_itemid_lists_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_exchange_item_info> list{};
	public:
		int32_t end_page{};

	public:
		mweb_exchange_itemid_lists_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &end_page);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
