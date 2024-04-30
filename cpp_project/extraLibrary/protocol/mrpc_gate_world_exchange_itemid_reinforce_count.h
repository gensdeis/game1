#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_exchange_reinforce_count_list.h"

namespace mir3d
{
	class mrpc_gate_world_exchange_itemid_reinforce_count_cs : public RpcPacket 
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
		mrpc_gate_world_exchange_itemid_reinforce_count_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_world_exchange_itemid_reinforce_count_cs, tag)
		{
		}
		mrpc_gate_world_exchange_itemid_reinforce_count_cs() : RpcPacket(mpe_rpc_cmd::gate_world_exchange_itemid_reinforce_count_cs)
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
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_world_exchange_itemid_reinforce_count_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_info = false;
		mps_exchange_reinforce_count_list info;
		mps_exchange_reinforce_count_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_exchange_reinforce_count_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_exchange_reinforce_count_list* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_exchange_reinforce_count_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_gate_world_exchange_itemid_reinforce_count_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_world_exchange_itemid_reinforce_count_sc, tag)
		{
		}
		mrpc_gate_world_exchange_itemid_reinforce_count_sc() : RpcPacket(mpe_rpc_cmd::gate_world_exchange_itemid_reinforce_count_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
