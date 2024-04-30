#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_global_exchange_item_info.h"

namespace mir3d
{
	class mrpc_gate_global_exchange_itemid_reinforce_list_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t exchange_type{};
	public:
		int32_t class_type{};
	public:
		int32_t item_id{};
	public:
		int32_t reinforce{};
	public:
		int32_t page{};
	public:
		mpe_exchange_type type{};

	public:
		mrpc_gate_global_exchange_itemid_reinforce_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_global_exchange_itemid_reinforce_list_cs, tag)
		{
		}
		mrpc_gate_global_exchange_itemid_reinforce_list_cs() : RpcPacket(mpe_rpc_cmd::gate_global_exchange_itemid_reinforce_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &exchange_type);
			protocol::SerializeType(pBuffer, &class_type);
			protocol::SerializeType(pBuffer, &item_id);
			protocol::SerializeType(pBuffer, &reinforce);
			protocol::SerializeType(pBuffer, &page);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_global_exchange_itemid_reinforce_list_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_global_exchange_item_info> list{};
	public:
		int32_t end_page{};

	public:
		mrpc_gate_global_exchange_itemid_reinforce_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_global_exchange_itemid_reinforce_list_sc, tag)
		{
		}
		mrpc_gate_global_exchange_itemid_reinforce_list_sc() : RpcPacket(mpe_rpc_cmd::gate_global_exchange_itemid_reinforce_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &end_page);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
