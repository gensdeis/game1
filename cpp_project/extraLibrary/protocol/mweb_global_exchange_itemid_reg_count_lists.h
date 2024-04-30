#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_exchange_search_info.h"
#include "struct/mps_global_exchange_search_item.h"

namespace mir3d
{
	class mweb_global_exchange_itemid_reg_count_lists_cs : public WebBasePacket 
	{
	public:
		std::vector<mps_exchange_search_info> search_info{};
	public:
		mpe_exchange_type type{};

	public:
		mweb_global_exchange_itemid_reg_count_lists_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &search_info);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_global_exchange_itemid_reg_count_lists_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_global_exchange_search_item> list{};

	public:
		mweb_global_exchange_itemid_reg_count_lists_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
