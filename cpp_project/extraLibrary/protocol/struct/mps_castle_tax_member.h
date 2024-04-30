#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_tax_member 	// 세율화면 길드 멤버 정보
	{
	public:
		mpe_guild_member_grade grade{};	// 등급
	public:
		std::string name{};	// 이름
	public:
		int64_t contribution{};	// 기여도
	public:
		int32_t contribution_weekly_point{};	// // 주간 공헌도
	public:
		int32_t contribution_accumulated_point{};	// // 누적 공헌도

	public:
		mps_castle_tax_member()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &grade);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &contribution);
			protocol::SerializeType(pBuffer, &contribution_weekly_point);
			protocol::SerializeType(pBuffer, &contribution_accumulated_point);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
