#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_town_arsenal_work 	// 병기창 작업
	{
	public:
		int32_t build_id{};	// 테이블아이디
	public:
		int32_t need_build_value{};	// 필요 미르의기운 수량
	public:
		int32_t build_value{};	// 현재 미르의기운 수량
	public:
		int32_t build_user_count{};	// 참여유저수

	public:
		mps_castle_town_arsenal_work()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &build_id);
			protocol::SerializeType(pBuffer, &need_build_value);
			protocol::SerializeType(pBuffer, &build_value);
			protocol::SerializeType(pBuffer, &build_user_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
