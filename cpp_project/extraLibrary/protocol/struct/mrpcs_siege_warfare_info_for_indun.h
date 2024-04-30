#pragma once
#include <vector>
#include <string>
#include "mps_siege_machine.h"
#include "mps_siege_machine.h"

namespace mir3d
{
	class mrpcs_siege_warfare_info_for_indun 
	{
	public:
		mpe_siege_castle_type castle_type{};	// 공성전 type
	public:
		mpe_siege_warfare_state state{};	// 공성전 상태
	public:
		int64_t first_guid{};	// 1위길드
	public:
		std::string first_guild_name{};	// 1위길드이름
	public:
		std::vector<int64_t> alliance_info{};	// 연합정보
	public:
		int64_t castle_owner_guid{};	// 성주길드
	public:
		std::string castle_owner_guild_name{};	// 성주길드이름
	public:
		std::vector<mps_siege_machine> atk_machine{};	// 공성 무기
	public:
		std::vector<mps_siege_machine> def_machine{};	// 수성 무기
	public:
		int64_t battle_start_time{};	// 공성 시작시간
	public:
		int64_t battle_end_time{};	// 공성 종료시간

	public:
		mrpcs_siege_warfare_info_for_indun()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &first_guid);
			protocol::SerializeType(pBuffer, &first_guild_name);
			protocol::SerializeType(pBuffer, &alliance_info);
			protocol::SerializeType(pBuffer, &castle_owner_guid);
			protocol::SerializeType(pBuffer, &castle_owner_guild_name);
			protocol::SerializeType(pBuffer, &atk_machine);
			protocol::SerializeType(pBuffer, &def_machine);
			protocol::SerializeType(pBuffer, &battle_start_time);
			protocol::SerializeType(pBuffer, &battle_end_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
