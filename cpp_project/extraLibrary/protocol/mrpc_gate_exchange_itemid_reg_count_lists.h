#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_exchange_search_info.h"
#include "struct/mps_exchange_search_item.h"

namespace mir3d
{
	class mrpc_gate_exchange_itemid_reg_count_lists_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_exchange_search_info> search_info{};

	public:
		mrpc_gate_exchange_itemid_reg_count_lists_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_exchange_itemid_reg_count_lists_cs, tag)
		{
		}
		mrpc_gate_exchange_itemid_reg_count_lists_cs() : RpcPacket(mpe_rpc_cmd::gate_exchange_itemid_reg_count_lists_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &search_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_exchange_itemid_reg_count_lists_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_exchange_search_item> list{};

	public:
		mrpc_gate_exchange_itemid_reg_count_lists_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_exchange_itemid_reg_count_lists_sc, tag)
		{
		}
		mrpc_gate_exchange_itemid_reg_count_lists_sc() : RpcPacket(mpe_rpc_cmd::gate_exchange_itemid_reg_count_lists_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
