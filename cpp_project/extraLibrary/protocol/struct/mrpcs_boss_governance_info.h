#pragma once
#include <vector>
#include <string>
#include "mps_boss_governance_summon_onoff.h"
#include "mps_boss_governance_server_info_total.h"

namespace mir3d
{
	class mrpcs_boss_governance_info 	// 보스 거버넌스 관련정보
	{
	public:
		std::vector<mps_boss_governance_summon_onoff> boss_summon_list{};	// 보스출현on/off 정보리스트
	public:
		std::vector<mps_boss_governance_server_info_total> last_governance_result{};	// 지난 주 거버넌스 결과
	public:
		int32_t next_reset_time{};	// 다음 거버넌스 갱신 시간
	public:
		std::string min_staking_amount{};	// 최소 스테이킹 수치

	public:
		mrpcs_boss_governance_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &boss_summon_list);
			protocol::SerializeType(pBuffer, &last_governance_result);
			protocol::SerializeType(pBuffer, &next_reset_time);
			protocol::SerializeType(pBuffer, &min_staking_amount);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
