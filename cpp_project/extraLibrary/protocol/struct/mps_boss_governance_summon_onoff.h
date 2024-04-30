#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_boss_governance_summon_onoff 	// 보스출현on/off 정보
	{
	public:
		int32_t gid{};	// 서버 아이디
	public:
		bool on_off{};	// on/off 플래그 (true/false)

	public:
		mps_boss_governance_summon_onoff()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &on_off);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
