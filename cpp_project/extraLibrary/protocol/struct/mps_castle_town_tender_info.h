#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_town_tender_info 	// 장원 경매 정보
	{
	public:
		int32_t town_id{};	// 장원 u아이디
	public:
		int32_t table_id{};	// 장원 테이블 아이디
	public:
		int32_t first_tender_value{};	// 장원 경매 최고가
	public:
		int64_t end_time{};	// 장원 경매 종료 시간
	public:
		int32_t enter_count{};	// 참여길드수

	public:
		mps_castle_town_tender_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &first_tender_value);
			protocol::SerializeType(pBuffer, &end_time);
			protocol::SerializeType(pBuffer, &enter_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
