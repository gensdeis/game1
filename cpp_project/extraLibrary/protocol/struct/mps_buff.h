#pragma once
#include <vector>
#include <string>
#include "mps_ability_value.h"

namespace mir3d
{
	class mps_buff 
	{
	public:
		int64_t buff_uid{};	// //버프 uid
	public:
		int32_t skill_ability_id{};	// //skill ability table 의 group id
	public:
		int32_t stack_count{};	// //중첩 수
	public:
		std::vector<mps_ability_value> buff_value{};	// //버프 정보 리스트
	public:
		int32_t remain_time{};	// //남은 시간
	public:
		int64_t end_time{};	// //종료시간
	public:
		mpe_chained_buff_name chained_name{};	// // 일괄종료일 경우 구분명

	public:
		mps_buff()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &buff_uid);
			protocol::SerializeType(pBuffer, &skill_ability_id);
			protocol::SerializeType(pBuffer, &stack_count);
			protocol::SerializeType(pBuffer, &buff_value);
			protocol::SerializeType(pBuffer, &remain_time);
			protocol::SerializeType(pBuffer, &end_time);
			protocol::SerializeEnum(pBuffer, &chained_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
