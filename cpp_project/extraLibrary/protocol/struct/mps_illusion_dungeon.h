#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_illusion_dungeon 	// 환상비경 정보
	{
	public:
		int32_t gid{};	// group_id
	public:
		int64_t reset_date{};	// 초기화일
	public:
		int32_t remaining_play_time{};	// 남은 플레이 시간
	public:
		int32_t charge_play_time{};	// 충전 플레이  시간
	public:
		int64_t charge_reset_date{};	// 충전 시간의 다음 초기화 날짜(이벤트 종료일)

	public:
		mps_illusion_dungeon()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &reset_date);
			protocol::SerializeType(pBuffer, &remaining_play_time);
			protocol::SerializeType(pBuffer, &charge_play_time);
			protocol::SerializeType(pBuffer, &charge_reset_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
