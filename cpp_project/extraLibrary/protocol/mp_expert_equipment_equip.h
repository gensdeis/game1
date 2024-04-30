#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_expert_equipment_info.h"

namespace mir3d
{
	class mp_expert_equipment_equip_cs : public BasePacket 
	{
	public:
		int32_t expert_equipment_tid{};	// "대상 전직 장비 테이블 id"

	public:
		mp_expert_equipment_equip_cs() : BasePacket(mpe_cmd::expert_equipment_equip_cs)
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

	class mp_expert_equipment_equip_sc : public BasePacket 
	{
	public:
		std::vector<mps_expert_equipment_info> expert_equipment_list{};	// "변경된 전직 장비 목록"
	public:
		std::vector<int32_t> list_special_move_slot{};	// "변경된 필살기 슬롯 정보"

	public:
		mp_expert_equipment_equip_sc() : BasePacket(mpe_cmd::expert_equipment_equip_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &expert_equipment_list);
			protocol::SerializeType(pBuffer, &list_special_move_slot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
