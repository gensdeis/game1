#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_expert_equipment_info.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_expert_equipment_enchant_stone_equip_cs : public BasePacket 
	{
	public:
		int32_t expert_equipment_tid{};	// "대상 전직 장비 테이블 id"
	public:
		uint8_t slot_num{};	// "소켓번호 1~3"
	public:
		int64_t enchant_stone_iuid{};	// "용령석 iuid"

	public:
		mp_expert_equipment_enchant_stone_equip_cs() : BasePacket(mpe_cmd::expert_equipment_enchant_stone_equip_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &expert_equipment_tid);
			protocol::SerializeType(pBuffer, &slot_num);
			protocol::SerializeType(pBuffer, &enchant_stone_iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_expert_equipment_enchant_stone_equip_sc : public BasePacket 
	{
	private:
		bool flag_expert_equipment_info = false;
		mps_expert_equipment_info expert_equipment_info;	// "용령석 착용 완료된 전직 장비 정보."
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
	private:
		bool flag_update_stone_item = false;
		mps_item_add update_stone_item;	// "착용 및 착용해제된 용령석 아이템"
		mps_item_add* p_update_stone_item = nullptr;
	public:
		bool has_update_stone_item() const
		{
			return flag_update_stone_item;
		}
		mps_item_add* alloc_update_stone_item()
		{
			flag_update_stone_item = true;
			return &update_stone_item;
		}
		const mps_item_add* get_update_stone_item() const
		{
			if (true == flag_update_stone_item)
			{
				if (nullptr == p_update_stone_item)
				{
					return &update_stone_item;
				}
				return p_update_stone_item;
			}
			return nullptr;
		}
		void set_update_stone_item(mps_item_add* in_update_stone_item)
		{
			if (nullptr == p_update_stone_item)
			{
				p_update_stone_item = in_update_stone_item;
				flag_update_stone_item = true;
			}
		}

	public:
		mp_expert_equipment_enchant_stone_equip_sc() : BasePacket(mpe_cmd::expert_equipment_enchant_stone_equip_sc)
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
			protocol::SerializeType(pBuffer, &flag_update_stone_item);
			if (true == flag_update_stone_item)
			{
				if (nullptr != p_update_stone_item)
					protocol::SerializeType(pBuffer, p_update_stone_item);
				else
					protocol::SerializeType(pBuffer, &update_stone_item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
