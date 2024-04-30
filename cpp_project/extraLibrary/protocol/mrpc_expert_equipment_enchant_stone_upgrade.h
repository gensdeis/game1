#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_expert_equipment_enchant_stone_upgrade_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};	// "캐릭터UID"
	public:
		int32_t table_id{};	// "엑셀테이블의 신기id"
	public:
		uint8_t slot_num{};	// "용령석이 장착된 신기 슬롯 1~3"
	public:
		int64_t enchant_stone_iuid{};	// "용령석 iuid"
	public:
		int32_t upgrade_value{};	// "갱신될 강화도"
	private:
		bool flag_sub_items = false;
		mps_item_add sub_items;	// "재화 및 소진 재료들"
		mps_item_add* p_sub_items = nullptr;
	public:
		bool has_sub_items() const
		{
			return flag_sub_items;
		}
		mps_item_add* alloc_sub_items()
		{
			flag_sub_items = true;
			return &sub_items;
		}
		const mps_item_add* get_sub_items() const
		{
			if (true == flag_sub_items)
			{
				if (nullptr == p_sub_items)
				{
					return &sub_items;
				}
				return p_sub_items;
			}
			return nullptr;
		}
		void set_sub_items(mps_item_add* in_sub_items)
		{
			if (nullptr == p_sub_items)
			{
				p_sub_items = in_sub_items;
				flag_sub_items = true;
			}
		}

	public:
		mrpc_expert_equipment_enchant_stone_upgrade_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::expert_equipment_enchant_stone_upgrade_cs, tag)
		{
		}
		mrpc_expert_equipment_enchant_stone_upgrade_cs() : RpcPacket(mpe_rpc_cmd::expert_equipment_enchant_stone_upgrade_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &slot_num);
			protocol::SerializeType(pBuffer, &enchant_stone_iuid);
			protocol::SerializeType(pBuffer, &upgrade_value);
			protocol::SerializeType(pBuffer, &flag_sub_items);
			if (true == flag_sub_items)
			{
				if (nullptr != p_sub_items)
					protocol::SerializeType(pBuffer, p_sub_items);
				else
					protocol::SerializeType(pBuffer, &sub_items);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_expert_equipment_enchant_stone_upgrade_sc : public RpcPacket 
	{

	public:
		mrpc_expert_equipment_enchant_stone_upgrade_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::expert_equipment_enchant_stone_upgrade_sc, tag)
		{
		}
		mrpc_expert_equipment_enchant_stone_upgrade_sc() : RpcPacket(mpe_rpc_cmd::expert_equipment_enchant_stone_upgrade_sc)
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
