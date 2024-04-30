#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_damage_list.h"

namespace mir3d
{
	class mp_skill_damage_result_cs : public BasePacket 
	{

	public:
		mp_skill_damage_result_cs() : BasePacket(mpe_cmd::skill_damage_result_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_skill_damage_result_sc : public BasePacket 
	{
	public:
		int64_t owner_uid{};	// player uid
	public:
		int32_t skill_id{};	// 스킬 id
	public:
		int32_t target_tile_index{};	// 스킬 타겟 cell index
	public:
		std::vector<mps_damage_list> target_list{};	// 타겟 데미치 처리 정보 list
	public:
		int64_t skill_uid{};	// 스킬 uid
	public:
		mpe_direction skill_dir{};	// 스킬 방향
	public:
		int32_t remain_time{};	// 스킬 남은 시간(ex 장판)

	public:
		mp_skill_damage_result_sc() : BasePacket(mpe_cmd::skill_damage_result_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &owner_uid);
			protocol::SerializeType(pBuffer, &skill_id);
			protocol::SerializeType(pBuffer, &target_tile_index);
			protocol::SerializeType(pBuffer, &target_list);
			protocol::SerializeType(pBuffer, &skill_uid);
			protocol::SerializeEnum(pBuffer, &skill_dir);
			protocol::SerializeType(pBuffer, &remain_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
