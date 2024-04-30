#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_exchange_search_info.h"
#include "struct/mps_global_exchange_search_item.h"

namespace mir3d
{
	class mp_gate_global_exchange_itemid_reg_count_lists_cs : public BasePacket 
	{
	public:
		std::vector<mps_exchange_search_info> search_info{};
	public:
		mpe_exchange_type type{};

	public:
		mp_gate_global_exchange_itemid_reg_count_lists_cs() : BasePacket(mpe_cmd::gate_global_exchange_itemid_reg_count_lists_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &search_info);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_global_exchange_itemid_reg_count_lists_sc : public BasePacket 
	{
	public:
		std::vector<mps_global_exchange_search_item> list{};

	public:
		mp_gate_global_exchange_itemid_reg_count_lists_sc() : BasePacket(mpe_cmd::gate_global_exchange_itemid_reg_count_lists_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
