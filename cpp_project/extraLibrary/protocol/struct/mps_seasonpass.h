#pragma once
#include <vector>
#include <string>
#include "mps_reward_value.h"

namespace mir3d
{
	class mps_seasonpass 
	{
	public:
		int32_t season_number{};
	public:
		int32_t season_lv{};	// 시즌레벨
	public:
		int32_t season_exp{};	// 시즌 경험치
	public:
		int32_t unlock_lv{};	// 해금레벨
	public:
		int32_t unlock_time{};	// 다음해금시간
	public:
		int32_t free_reward{};	// 무료보상(비트값)
	public:
		int32_t pass_reward{};	// 구매보상(비트값)
	public:
		int32_t day_reward{};	// 일일보상 수령시간
	public:
		bool complete_reward{};	// 완료보상
	public:
		int32_t end_date{};	// 종료시간
	public:
		int32_t buy_date{};	// 시즌패스 구매시간
	public:
		std::vector<mps_reward_value> list_end_reward{};	// 종료보상

	public:
		mps_seasonpass()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &season_number);
			protocol::SerializeType(pBuffer, &season_lv);
			protocol::SerializeType(pBuffer, &season_exp);
			protocol::SerializeType(pBuffer, &unlock_lv);
			protocol::SerializeType(pBuffer, &unlock_time);
			protocol::SerializeType(pBuffer, &free_reward);
			protocol::SerializeType(pBuffer, &pass_reward);
			protocol::SerializeType(pBuffer, &day_reward);
			protocol::SerializeType(pBuffer, &complete_reward);
			protocol::SerializeType(pBuffer, &end_date);
			protocol::SerializeType(pBuffer, &buy_date);
			protocol::SerializeType(pBuffer, &list_end_reward);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
