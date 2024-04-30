#pragma once
#include <vector>
#include <string>
#include "mps_castle_town_info_detail.h"

namespace mir3d
{
	class mps_castle_town_info 	// 장원 기본정보
	{
	public:
		int32_t town_id{};	// 장원아이디
	public:
		uint8_t town_grade{};	// 장원등급 / enum_table  /town_type
	public:
		int64_t owner_guid{};	// 장원길드
	public:
		int32_t rental_end_time{};	// 대여 종료시간
	public:
		int32_t continuation_delay_time{};	// 대여 연장 대기 시간
	private:
		bool flag_info_detail = false;
		mps_castle_town_info_detail info_detail;	// 장원 상세정보
		mps_castle_town_info_detail* p_info_detail = nullptr;
	public:
		bool has_info_detail() const
		{
			return flag_info_detail;
		}
		mps_castle_town_info_detail* alloc_info_detail()
		{
			flag_info_detail = true;
			return &info_detail;
		}
		const mps_castle_town_info_detail* get_info_detail() const
		{
			if (true == flag_info_detail)
			{
				if (nullptr == p_info_detail)
				{
					return &info_detail;
				}
				return p_info_detail;
			}
			return nullptr;
		}
		void set_info_detail(mps_castle_town_info_detail* in_info_detail)
		{
			if (nullptr == p_info_detail)
			{
				p_info_detail = in_info_detail;
				flag_info_detail = true;
			}
		}

	public:
		mps_castle_town_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeType(pBuffer, &town_grade);
			protocol::SerializeType(pBuffer, &owner_guid);
			protocol::SerializeType(pBuffer, &rental_end_time);
			protocol::SerializeType(pBuffer, &continuation_delay_time);
			protocol::SerializeType(pBuffer, &flag_info_detail);
			if (true == flag_info_detail)
			{
				if (nullptr != p_info_detail)
					protocol::SerializeType(pBuffer, p_info_detail);
				else
					protocol::SerializeType(pBuffer, &info_detail);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
