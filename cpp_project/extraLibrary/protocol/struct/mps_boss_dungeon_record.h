#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_boss_dungeon_record 	// 보스 던전별 타임어택 기록
	{
	public:
		int32_t dungeon_id{};	// 던전 ID
	public:
		int64_t record{};	// record 기록

	public:
		mps_boss_dungeon_record()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &dungeon_id);
			protocol::SerializeType(pBuffer, &record);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
