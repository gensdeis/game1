#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_boss_governance_treasurebox 	// 보스 거버넌스 보물상자 추가확률관련 정보
	{
	public:
		int32_t server_count{};	// 월드 서버에 연결된 게임서버 수
	public:
		int32_t benefit_count{};	// 혜택을 받는 서버 수
	public:
		uint8_t rank{};	// 서버 랭킹

	public:
		mrpcs_boss_governance_treasurebox()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &server_count);
			protocol::SerializeType(pBuffer, &benefit_count);
			protocol::SerializeType(pBuffer, &rank);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
