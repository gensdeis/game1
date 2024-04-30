#pragma once
#include <vector>
#include <string>
#include "mps_damage_result.h"
#include "mps_buff.h"

namespace mir3d
{
	class mps_damage_list 
	{
	public:
		int64_t target_uid{};	// //타겟 uid
	public:
		std::vector<mps_damage_result> damage_list{};	// //데미지 정보 리스트
	public:
		std::vector<mps_buff> buff_info{};	// //버프 정보 리스트
	public:
		int32_t tile_index{};	// //타겟 cell index
	public:
		int64_t contribution_uid{};	// contribution_type이 FirstAttacker면 character uid, ServerAttacker면 gid 소유권이 없으면 0
	public:
		uint8_t contribution_type{};	// 몬스터 소유권 타입, table enum의 ItemPriority 값을 따름
	public:
		mpe_skill_action_result skill_action_result{};	// //스킬 엑션 결과

	public:
		mps_damage_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &target_uid);
			protocol::SerializeType(pBuffer, &damage_list);
			protocol::SerializeType(pBuffer, &buff_info);
			protocol::SerializeType(pBuffer, &tile_index);
			protocol::SerializeType(pBuffer, &contribution_uid);
			protocol::SerializeType(pBuffer, &contribution_type);
			protocol::SerializeEnum(pBuffer, &skill_action_result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
