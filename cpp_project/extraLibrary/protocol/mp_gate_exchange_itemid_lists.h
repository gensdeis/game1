#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_exchange_item_info.h"

namespace mir3d
{
	class mp_gate_exchange_itemid_lists_cs : public BasePacket 
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
		mp_gate_exchange_itemid_lists_cs() : BasePacket(mpe_cmd::gate_exchange_itemid_lists_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &exchange_type);
			protocol::SerializeType(pBuffer, &class_type);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &page);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_exchange_itemid_lists_sc : public BasePacket 
	{
	public:
		std::vector<mps_exchange_item_info> list{};
	public:
		int32_t end_page{};

	public:
		mp_gate_exchange_itemid_lists_sc() : BasePacket(mpe_cmd::gate_exchange_itemid_lists_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &end_page);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
