#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_town_character_specialties_work 	// "특산물 건물 개인 작업 ( 채광
	{
	public:
		mpe_castle_town_specialties_pos specialties_pos{};	// 작업 타입
	public:
		int64_t end_time{};	// 종료시간

	public:
		mps_castle_town_character_specialties_work()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &specialties_pos);
			protocol::SerializeType(pBuffer, &end_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
