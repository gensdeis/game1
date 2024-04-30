#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_town_info 	// 길드 장원 정보
	{
	public:
		int32_t town_id{};	// 장원아이디
	public:
		int32_t table_id{};	// 해당장원 테이블아이디
	public:
		int32_t rental_end_time{};	// 대여 종료시간
	public:
		int32_t continuation_delay_time{};	// 대여 연장 대기 시간

	public:
		mps_guild_town_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &rental_end_time);
			protocol::SerializeType(pBuffer, &continuation_delay_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
