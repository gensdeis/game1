#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_expert_equipment_create_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};	// "캐릭터UID"
	public:
		int32_t table_id{};	// "엑셀테이블의 신기id"
	private:
		bool flag_sub_item = false;
		mps_item_add sub_item;	// "소진 재료"
		mps_item_add* p_sub_item = nullptr;
	public:
		bool has_sub_item() const
		{
			return flag_sub_item;
		}
		mps_item_add* alloc_sub_item()
		{
			flag_sub_item = true;
			return &sub_item;
		}
		const mps_item_add* get_sub_item() const
		{
			if (true == flag_sub_item)
			{
				if (nullptr == p_sub_item)
				{
					return &sub_item;
				}
				return p_sub_item;
			}
			return nullptr;
		}
		void set_sub_item(mps_item_add* in_sub_item)
		{
			if (nullptr == p_sub_item)
			{
				p_sub_item = in_sub_item;
				flag_sub_item = true;
			}
		}

	public:
		mrpc_expert_equipment_create_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::expert_equipment_create_cs, tag)
		{
		}
		mrpc_expert_equipment_create_cs() : RpcPacket(mpe_rpc_cmd::expert_equipment_create_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &flag_sub_item);
			if (true == flag_sub_item)
			{
				if (nullptr != p_sub_item)
					protocol::SerializeType(pBuffer, p_sub_item);
				else
					protocol::SerializeType(pBuffer, &sub_item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_expert_equipment_create_sc : public RpcPacket 
	{

	public:
		mrpc_expert_equipment_create_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::expert_equipment_create_sc, tag)
		{
		}
		mrpc_expert_equipment_create_sc() : RpcPacket(mpe_rpc_cmd::expert_equipment_create_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
