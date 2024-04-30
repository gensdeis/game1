#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_pet_info.h"
#include "struct/mps_pet_info.h"

namespace mir3d
{
	class mp_pet_team_equip_cs : public BasePacket 
	{
	public:
		mpe_pet_team team{};	// 장착팀 - max이면 해제
	public:
		std::vector<int32_t> tid{};	// 장착 펫들의 tid

	public:
		mp_pet_team_equip_cs() : BasePacket(mpe_cmd::pet_team_equip_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &team);
			protocol::SerializeType(pBuffer, &tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_pet_team_equip_sc : public BasePacket 
	{
	public:
		std::vector<mps_pet_info> equip_pet{};	// 장착펫
	public:
		std::vector<mps_pet_info> release_pet{};	// 해제펫
	public:
		std::vector<int32_t> list_special_move_slot{};	// 필살기 슬롯 배치

	public:
		mp_pet_team_equip_sc() : BasePacket(mpe_cmd::pet_team_equip_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &equip_pet);
			protocol::SerializeType(pBuffer, &release_pet);
			protocol::SerializeType(pBuffer, &list_special_move_slot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
