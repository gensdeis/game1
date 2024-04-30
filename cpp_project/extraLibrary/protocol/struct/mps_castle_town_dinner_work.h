#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_town_dinner_work 	// 만찬 작업
	{
	public:
		int32_t dinner_table_id{};	// 테이블아이디
	public:
		int64_t dinner_end_time{};	// 만찬 종료시간
	public:
		int32_t dinner_user_count{};	// 참여유저수

	public:
		mps_castle_town_dinner_work()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &dinner_table_id);
			protocol::SerializeType(pBuffer, &dinner_end_time);
			protocol::SerializeType(pBuffer, &dinner_user_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
