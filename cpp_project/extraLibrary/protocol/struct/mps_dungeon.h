#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_dungeon 	// 인던 정보
	{
	public:
		int32_t gid{};
	public:
		uint8_t dungeon_type{};
	public:
		int64_t lasttime{};
	public:
		int32_t count{};
	public:
		uint8_t use_item_idx{};

	public:
		mps_dungeon()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &dungeon_type);
			protocol::SerializeType(pBuffer, &lasttime);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &use_item_idx);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
