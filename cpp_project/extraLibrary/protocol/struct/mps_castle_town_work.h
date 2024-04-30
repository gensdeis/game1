#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_town_work 	// 장원 작업
	{
	public:
		int32_t work_id{};	// 작업 아이디
	public:
		int64_t guid{};
	public:
		int32_t town_id{};
	public:
		mpe_castle_town_work_type work_type{};	// 작업 타입
	public:
		mpe_castle_town_detail_pos house_pos{};
	public:
		int32_t house_growth_table_id{};	// house growth table id
	public:
		int64_t start_date_time{};	// 시작시간
	public:
		int64_t end_date_time{};	// 종료시간
	public:
		bool is_end{};	// 종료여부

	public:
		mps_castle_town_work()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &work_id);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeEnum(pBuffer, &work_type);
			protocol::SerializeEnum(pBuffer, &house_pos);
			protocol::SerializeType(pBuffer, &house_growth_table_id);
			protocol::SerializeType(pBuffer, &start_date_time);
			protocol::SerializeType(pBuffer, &end_date_time);
			protocol::SerializeType(pBuffer, &is_end);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
