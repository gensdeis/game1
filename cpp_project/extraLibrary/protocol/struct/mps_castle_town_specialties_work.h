#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_town_specialties_work 	// 특산물 건물 작업
	{
	public:
		mpe_castle_town_specialties_pos specialties_pos{};	// 작업 타입
	public:
		int32_t gather_value{};
	public:
		int64_t end_delivery_time{};	// 납품종료시간
	public:
		int32_t gather_table_id{};	// gatherHouseGrowthTable id

	public:
		mps_castle_town_specialties_work()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &specialties_pos);
			protocol::SerializeType(pBuffer, &gather_value);
			protocol::SerializeType(pBuffer, &end_delivery_time);
			protocol::SerializeType(pBuffer, &gather_table_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
