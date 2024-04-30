#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_siege_result_score 
	{
	public:
		mpe_siege_team_index victory_team{};
	public:
		int32_t play_time{};
	public:
		uint8_t atk_user_count{};
	public:
		uint8_t def_user_count{};
	public:
		std::vector<int32_t> destroy_wall_time{};	// 테이블 index 참조
	public:
		int32_t destroy_all_def_tower_time{};	// 모든 수성탑이 부서진 시간
	public:
		int64_t win_guild_uid{};

	public:
		mps_siege_result_score()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &victory_team);
			protocol::SerializeType(pBuffer, &play_time);
			protocol::SerializeType(pBuffer, &atk_user_count);
			protocol::SerializeType(pBuffer, &def_user_count);
			protocol::SerializeType(pBuffer, &destroy_wall_time);
			protocol::SerializeType(pBuffer, &destroy_all_def_tower_time);
			protocol::SerializeType(pBuffer, &win_guild_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
