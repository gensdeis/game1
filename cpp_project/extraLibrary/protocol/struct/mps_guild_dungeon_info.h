#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_dungeon_info 
	{
	public:
		int64_t indun_uid{};
	public:
		int32_t tid{};
	public:
		int64_t expire_time{};
	public:
		int32_t open_count_reset_time{};
	public:
		std::vector<uint8_t> list_open_count{};	// 입장 횟수
	public:
		std::vector<uint8_t> list_charge_open_count{};	// 입장 충전 수
	public:
		std::vector<uint8_t> list_charge_count{};	// 충전 횟수

	public:
		mps_guild_dungeon_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &expire_time);
			protocol::SerializeType(pBuffer, &open_count_reset_time);
			protocol::SerializeType(pBuffer, &list_open_count);
			protocol::SerializeType(pBuffer, &list_charge_open_count);
			protocol::SerializeType(pBuffer, &list_charge_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
