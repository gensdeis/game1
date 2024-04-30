#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_cash_shop_item.h"

namespace mir3d
{
	class mp_gate_cash_shop_item_list_cs : public BasePacket 
	{
	public:
		int64_t uid{};

	public:
		mp_gate_cash_shop_item_list_cs() : BasePacket(mpe_cmd::gate_cash_shop_item_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_cash_shop_item_list_sc : public BasePacket 
	{
	public:
		int64_t uid{};
	public:
		std::vector<mps_cash_shop_item> list{};

	public:
		mp_gate_cash_shop_item_list_sc() : BasePacket(mpe_cmd::gate_cash_shop_item_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
