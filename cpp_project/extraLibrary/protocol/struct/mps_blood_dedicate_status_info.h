#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_blood_dedicate_status_info 	// 봉혈 현황 정보
	{
	public:
		int32_t id{};	// barter 테이블 구분자
	public:
		int32_t limit_type{};	// 횟수 제한 타입
	public:
		int32_t count{};	// 구매 수량
	public:
		int32_t last_buy_date{};	// 마지막 구매일

	public:
		mps_blood_dedicate_status_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &limit_type);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &last_buy_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
