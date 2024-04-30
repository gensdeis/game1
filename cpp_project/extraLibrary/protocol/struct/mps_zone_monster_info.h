#pragma once
#include <vector>
#include <string>
#include "mps_buff.h"

namespace mir3d
{
	class mps_zone_monster_info 
	{
	public:
		int32_t hp{};	// HP
	public:
		mpe_move_type move_type{};
	public:
		int32_t end_cell{};	// 도착지좌표
	public:
		int32_t mhp{};	// maxHP
	public:
		std::vector<mps_buff> buff_list{};
	public:
		int64_t contribution_uid{};	// contribution_type이 FirstAttacker면 character uid, ServerAttacker면 gid 소유권이 없으면 0
	public:
		uint8_t contribution_type{};	// 몬스터 소유권 타입, table enum의 ItemPriority 값을 따름
	public:
		bool appeared{};	// 스폰시연출여부
	public:
		int32_t object_id{};
	public:
		int32_t phase_change_state{};	// 페이즈 아이디

	public:
		mps_zone_monster_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &hp);
			protocol::SerializeEnum(pBuffer, &move_type);
			protocol::SerializeType(pBuffer, &end_cell);
			protocol::SerializeType(pBuffer, &mhp);
			protocol::SerializeType(pBuffer, &buff_list);
			protocol::SerializeType(pBuffer, &contribution_uid);
			protocol::SerializeType(pBuffer, &contribution_type);
			protocol::SerializeType(pBuffer, &appeared);
			protocol::SerializeType(pBuffer, &object_id);
			protocol::SerializeType(pBuffer, &phase_change_state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
