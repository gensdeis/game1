#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_boss_dungeon_reward 	// 보스 던전 보상 ( UI 표기용 )
	{
	public:
		int32_t item_id{};	// 아이템 ID
	public:
		int32_t count{};	// item count

	public:
		mps_boss_dungeon_reward()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &item_id);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
