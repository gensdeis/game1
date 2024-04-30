#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_monarch_info 	// 소환던전(요마)진행정보
	{
	public:
		int32_t item_id{};	// 소환석 item_id
	public:
		int32_t remain_monster_count{};	// 생존몬스터 수
	public:
		int32_t total_spawn_count{};	// 총 소환 수

	public:
		mps_monarch_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &item_id);
			protocol::SerializeType(pBuffer, &remain_monster_count);
			protocol::SerializeType(pBuffer, &total_spawn_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
