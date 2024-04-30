#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_blood_dedicate_worldboss_info 	// 봉혈 시스템 출현 몬스터 정보
	{
	public:
		int32_t monster_id{};	// 몬스터 아이디
	public:
		int32_t zone_id{};	// 출현 맵 아이디
	public:
		int32_t summon_point{};	// 현재 월드보스소환 누적포인트
	public:
		int32_t summon_time{};	// 보스 출현 시간
	public:
		mpe_blood_dedicate_worldboss_state state{};	// 보스소환 상태

	public:
		mps_blood_dedicate_worldboss_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &monster_id);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &summon_point);
			protocol::SerializeType(pBuffer, &summon_time);
			protocol::SerializeEnum(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
