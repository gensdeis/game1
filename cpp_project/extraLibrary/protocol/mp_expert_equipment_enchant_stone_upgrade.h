#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_expert_equipment_info.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_expert_equipment_enchant_stone_upgrade_cs : public BasePacket 
	{
	public:
		int32_t expert_equipment_tid{};	// "신기테이블id"
	public:
		uint8_t slot_num{};	// "대상 용령석이 착용된 신기 슬롯 번호 1~3"
	public:
		int64_t use_stone_iuid{};	// "재료로 사용될 용령석iuid"

	public:
		mp_expert_equipment_enchant_stone_upgrade_cs() : BasePacket(mpe_cmd::expert_equipment_enchant_stone_upgrade_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &expert_equipment_tid);
			protocol::SerializeType(pBuffer, &slot_num);
			protocol::SerializeType(pBuffer, &use_stone_iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_expert_equipment_enchant_stone_upgrade_sc : public BasePacket 
	{
	private:
		bool flag_expert_equipment_info = false;
		mps_expert_equipment_info expert_equipment_info;	// "해당 용령석 착용한 신기 정보"
		mps_expert_equipment_info* p_expert_equipment_info = nullptr;
	public:
		bool has_expert_equipment_info() const
		{
			return flag_expert_equipment_info;
		}
		mps_expert_equipment_info* alloc_expert_equipment_info()
		{
			flag_expert_equipment_info = true;
			return &expert_equipment_info;
		}
		const mps_expert_equipment_info* get_expert_equipment_info() const
		{
			if (true == flag_expert_equipment_info)
			{
				if (nullptr == p_expert_equipment_info)
				{
					return &expert_equipment_info;
				}
				return p_expert_equipment_info;
			}
			return nullptr;
		}
		void set_expert_equipment_info(mps_expert_equipment_info* in_expert_equipment_info)
		{
			if (nullptr == p_expert_equipment_info)
			{
				p_expert_equipment_info = in_expert_equipment_info;
				flag_expert_equipment_info = true;
			}
		}
	public:
		uint8_t slot_num{};	// "해당 용령석 착용된 신기의 슬롯번호 1~3"
	private:
		bool flag_sub_item = false;
		mps_item_add sub_item;	// "소모된 아이템 정보"
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
		mpe_upgrade_state upgrade_state{};

	public:
		mp_expert_equipment_enchant_stone_upgrade_sc() : BasePacket(mpe_cmd::expert_equipment_enchant_stone_upgrade_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_expert_equipment_info);
			if (true == flag_expert_equipment_info)
			{
				if (nullptr != p_expert_equipment_info)
					protocol::SerializeType(pBuffer, p_expert_equipment_info);
				else
					protocol::SerializeType(pBuffer, &expert_equipment_info);
			}
			protocol::SerializeType(pBuffer, &slot_num);
			protocol::SerializeType(pBuffer, &flag_sub_item);
			if (true == flag_sub_item)
			{
				if (nullptr != p_sub_item)
					protocol::SerializeType(pBuffer, p_sub_item);
				else
					protocol::SerializeType(pBuffer, &sub_item);
			}
			protocol::SerializeEnum(pBuffer, &upgrade_state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
