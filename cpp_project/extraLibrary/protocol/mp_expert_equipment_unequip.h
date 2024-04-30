#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_expert_equipment_info.h"

namespace mir3d
{
	class mp_expert_equipment_unequip_cs : public BasePacket 
	{
	public:
		int32_t expert_equipment_tid{};	// "대상 전직 장비 테이블 id"

	public:
		mp_expert_equipment_unequip_cs() : BasePacket(mpe_cmd::expert_equipment_unequip_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &expert_equipment_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_expert_equipment_unequip_sc : public BasePacket 
	{
	private:
		bool flag_unequip_expert_equipment = false;
		mps_expert_equipment_info unequip_expert_equipment;	// "변경된 전직 장비"
		mps_expert_equipment_info* p_unequip_expert_equipment = nullptr;
	public:
		bool has_unequip_expert_equipment() const
		{
			return flag_unequip_expert_equipment;
		}
		mps_expert_equipment_info* alloc_unequip_expert_equipment()
		{
			flag_unequip_expert_equipment = true;
			return &unequip_expert_equipment;
		}
		const mps_expert_equipment_info* get_unequip_expert_equipment() const
		{
			if (true == flag_unequip_expert_equipment)
			{
				if (nullptr == p_unequip_expert_equipment)
				{
					return &unequip_expert_equipment;
				}
				return p_unequip_expert_equipment;
			}
			return nullptr;
		}
		void set_unequip_expert_equipment(mps_expert_equipment_info* in_unequip_expert_equipment)
		{
			if (nullptr == p_unequip_expert_equipment)
			{
				p_unequip_expert_equipment = in_unequip_expert_equipment;
				flag_unequip_expert_equipment = true;
			}
		}
	public:
		std::vector<int32_t> list_special_move_slot{};	// "변경된 필살기 슬롯 정보"

	public:
		mp_expert_equipment_unequip_sc() : BasePacket(mpe_cmd::expert_equipment_unequip_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_unequip_expert_equipment);
			if (true == flag_unequip_expert_equipment)
			{
				if (nullptr != p_unequip_expert_equipment)
					protocol::SerializeType(pBuffer, p_unequip_expert_equipment);
				else
					protocol::SerializeType(pBuffer, &unequip_expert_equipment);
			}
			protocol::SerializeType(pBuffer, &list_special_move_slot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
