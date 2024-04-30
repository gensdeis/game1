#pragma once
#include <vector>
#include <string>
#include "mps_castle_town_building_info.h"
#include "mps_castle_town_work.h"
#include "mps_castle_town_arsenal_work.h"
#include "mps_castle_town_dinner_work.h"
#include "mps_castle_town_specialties_work.h"

namespace mir3d
{
	class mrpcs_castle_town_info 	// 장원 기본정보
	{
	public:
		int32_t town_id{};	// 장원아이디
	public:
		int32_t table_id{};	// 장원테이블아이디
	public:
		uint8_t town_grade{};	// 장원등급 / enum_table  /town_type
	public:
		int64_t owner_guid{};	// 장원길드
	public:
		std::string owner_guild_name{};	// 장원길드이름
	public:
		std::string master_name{};	// 길드장이름
	public:
		int32_t rental_end_time{};	// 대여 종료시간
	public:
		int32_t continuation_delay_time{};	// 대여 연장 대기 시간
	public:
		bool is_enter{};	// 입주여부
	public:
		std::vector<mps_castle_town_building_info> info_detail{};	// 장원 상세정보
	public:
		std::vector<mps_castle_town_work> info_work{};	// 장원 작업정보
	private:
		bool flag_arsenal_work = false;
		mps_castle_town_arsenal_work arsenal_work;	// 병기창 작업
		mps_castle_town_arsenal_work* p_arsenal_work = nullptr;
	public:
		bool has_arsenal_work() const
		{
			return flag_arsenal_work;
		}
		mps_castle_town_arsenal_work* alloc_arsenal_work()
		{
			flag_arsenal_work = true;
			return &arsenal_work;
		}
		const mps_castle_town_arsenal_work* get_arsenal_work() const
		{
			if (true == flag_arsenal_work)
			{
				if (nullptr == p_arsenal_work)
				{
					return &arsenal_work;
				}
				return p_arsenal_work;
			}
			return nullptr;
		}
		void set_arsenal_work(mps_castle_town_arsenal_work* in_arsenal_work)
		{
			if (nullptr == p_arsenal_work)
			{
				p_arsenal_work = in_arsenal_work;
				flag_arsenal_work = true;
			}
		}
	private:
		bool flag_dinner_work = false;
		mps_castle_town_dinner_work dinner_work;	// 만찬 작업
		mps_castle_town_dinner_work* p_dinner_work = nullptr;
	public:
		bool has_dinner_work() const
		{
			return flag_dinner_work;
		}
		mps_castle_town_dinner_work* alloc_dinner_work()
		{
			flag_dinner_work = true;
			return &dinner_work;
		}
		const mps_castle_town_dinner_work* get_dinner_work() const
		{
			if (true == flag_dinner_work)
			{
				if (nullptr == p_dinner_work)
				{
					return &dinner_work;
				}
				return p_dinner_work;
			}
			return nullptr;
		}
		void set_dinner_work(mps_castle_town_dinner_work* in_dinner_work)
		{
			if (nullptr == p_dinner_work)
			{
				p_dinner_work = in_dinner_work;
				flag_dinner_work = true;
			}
		}
	public:
		std::vector<int64_t> dinner_user{};	// 만찬 유저
	public:
		std::vector<mps_castle_town_specialties_work> specialties_work{};	// 특산물 작업

	public:
		mrpcs_castle_town_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &town_grade);
			protocol::SerializeType(pBuffer, &owner_guid);
			protocol::SerializeType(pBuffer, &owner_guild_name);
			protocol::SerializeType(pBuffer, &master_name);
			protocol::SerializeType(pBuffer, &rental_end_time);
			protocol::SerializeType(pBuffer, &continuation_delay_time);
			protocol::SerializeType(pBuffer, &is_enter);
			protocol::SerializeType(pBuffer, &info_detail);
			protocol::SerializeType(pBuffer, &info_work);
			protocol::SerializeType(pBuffer, &flag_arsenal_work);
			if (true == flag_arsenal_work)
			{
				if (nullptr != p_arsenal_work)
					protocol::SerializeType(pBuffer, p_arsenal_work);
				else
					protocol::SerializeType(pBuffer, &arsenal_work);
			}
			protocol::SerializeType(pBuffer, &flag_dinner_work);
			if (true == flag_dinner_work)
			{
				if (nullptr != p_dinner_work)
					protocol::SerializeType(pBuffer, p_dinner_work);
				else
					protocol::SerializeType(pBuffer, &dinner_work);
			}
			protocol::SerializeType(pBuffer, &dinner_user);
			protocol::SerializeType(pBuffer, &specialties_work);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
