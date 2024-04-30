#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_boss_contribution 
	{
	public:
		int64_t uid{};	// contribution_type이 FirstAttacker면 character uid, ServerAttacker면 gid
	public:
		float contribution{};	// 기여도 비율
	public:
		uint8_t contribution_type{};	// table enum의 ItemPriority 값

	public:
		mps_boss_contribution()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &contribution);
			protocol::SerializeType(pBuffer, &contribution_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
