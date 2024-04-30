#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_league_info 
	{
	public:
		int32_t rank{};
	public:
		int32_t score{};
	public:
		uint16_t league{};
	public:
		int32_t win_count{};
	public:
		int32_t lose_count{};
	public:
		int32_t draw_count{};

	public:
		mps_guild_league_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &score);
			protocol::SerializeType(pBuffer, &league);
			protocol::SerializeType(pBuffer, &win_count);
			protocol::SerializeType(pBuffer, &lose_count);
			protocol::SerializeType(pBuffer, &draw_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
