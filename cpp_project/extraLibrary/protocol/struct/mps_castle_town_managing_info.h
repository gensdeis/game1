#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_town_managing_info 
	{
	public:
		mpe_castle_town_detail_pos house_pos{};	// 장원건물
	public:
		bool build{};	// 건물 생성 여부
	public:
		int32_t level{};
	public:
		mpe_castle_town_work_type work_type{};	// 작업 타입
	public:
		int64_t end_date_time{};	// 종료시간
	public:
		bool is_end{};	// 종료여부

	public:
		mps_castle_town_managing_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &house_pos);
			protocol::SerializeType(pBuffer, &build);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeEnum(pBuffer, &work_type);
			protocol::SerializeType(pBuffer, &end_date_time);
			protocol::SerializeType(pBuffer, &is_end);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
