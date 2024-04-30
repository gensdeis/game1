#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_arena_character_season_info 
	{
	public:
		int64_t battle_uid{};
	public:
		int32_t season_round{};
	public:
		int32_t add_score{};
	public:
		uint8_t win_lose{};

	public:
		mps_arena_character_season_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &battle_uid);
			protocol::SerializeType(pBuffer, &season_round);
			protocol::SerializeType(pBuffer, &add_score);
			protocol::SerializeType(pBuffer, &win_lose);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
