#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_global_party_governance_info 	// 파티 거버넌스 redis 정보
	{
	public:
		int32_t decide_date{};	// 서버결정 시간
	public:
		int32_t next_governance_date{};	// 다음 서버결정 시간
	public:
		int32_t governance_server_count{};	// 전체 거버넌스 적용 서버 갯수
	public:
		int32_t benefit_user_count{};	// 혜택 유저 수
	public:
		std::string min_staking_amount{};	// 서버 결정시 결정된 최소 스테이킹 수치

	public:
		mrpcs_global_party_governance_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &decide_date);
			protocol::SerializeType(pBuffer, &next_governance_date);
			protocol::SerializeType(pBuffer, &governance_server_count);
			protocol::SerializeType(pBuffer, &benefit_user_count);
			protocol::SerializeType(pBuffer, &min_staking_amount);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
