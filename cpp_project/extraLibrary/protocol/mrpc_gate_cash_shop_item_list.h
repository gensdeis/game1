#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_cash_shop_item.h"

namespace mir3d
{
	class mrpc_gate_cash_shop_item_list_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t uid{};

	public:
		mrpc_gate_cash_shop_item_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_cash_shop_item_list_cs, tag)
		{
		}
		mrpc_gate_cash_shop_item_list_cs() : RpcPacket(mpe_rpc_cmd::gate_cash_shop_item_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_cash_shop_item_list_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t uid{};
	public:
		std::vector<mps_cash_shop_item> list{};

	public:
		mrpc_gate_cash_shop_item_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_cash_shop_item_list_sc, tag)
		{
		}
		mrpc_gate_cash_shop_item_list_sc() : RpcPacket(mpe_rpc_cmd::gate_cash_shop_item_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
