#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_quest_history 	// 퀘스트진행내역
	{
	public:
		uint16_t last_main_id{};
	public:
		int32_t count{};	// *2byte
	public:
		std::vector<uint8_t> data{};
	public:
		int32_t repute_quest_last_reset_time{};
	public:
		int32_t repute_quest_finish_count{};
	public:
		int32_t repute_quest_last_daily_reset_time{};
	public:
		int32_t repute_quest_daily_reset_count{};
	public:
		int32_t guild_quest_finish_count{};
	public:
		int32_t guild_quest_last_reset_time{};
	public:
		int32_t guild_office_quest_finish_count{};
	public:
		int32_t guild_office_quest_last_reset_time{};
	public:
		int32_t profession_quest_count{};	// *2byte
	public:
		std::vector<uint8_t> profession_quest_data{};
	public:
		int32_t profession_quest_reset_time{};
	public:
		int32_t area_quest_finish_count{};
	public:
		int32_t area_quest_finish_count_reset_time{};
	public:
		uint8_t field_boss_kill_count{};
	public:
		uint8_t arena_join_count{};

	public:
		mps_quest_history()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &last_main_id);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &data);
			protocol::SerializeType(pBuffer, &repute_quest_last_reset_time);
			protocol::SerializeType(pBuffer, &repute_quest_finish_count);
			protocol::SerializeType(pBuffer, &repute_quest_last_daily_reset_time);
			protocol::SerializeType(pBuffer, &repute_quest_daily_reset_count);
			protocol::SerializeType(pBuffer, &guild_quest_finish_count);
			protocol::SerializeType(pBuffer, &guild_quest_last_reset_time);
			protocol::SerializeType(pBuffer, &guild_office_quest_finish_count);
			protocol::SerializeType(pBuffer, &guild_office_quest_last_reset_time);
			protocol::SerializeType(pBuffer, &profession_quest_count);
			protocol::SerializeType(pBuffer, &profession_quest_data);
			protocol::SerializeType(pBuffer, &profession_quest_reset_time);
			protocol::SerializeType(pBuffer, &area_quest_finish_count);
			protocol::SerializeType(pBuffer, &area_quest_finish_count_reset_time);
			protocol::SerializeType(pBuffer, &field_boss_kill_count);
			protocol::SerializeType(pBuffer, &arena_join_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
