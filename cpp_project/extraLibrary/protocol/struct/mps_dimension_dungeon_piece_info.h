#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_dimension_dungeon_piece_info 	// 차원비경 차원조각 개수 정보
	{
	public:
		int32_t gid{};	// 서버 gid
	public:
		int32_t total_amount{};	// 차원조각 개수

	public:
		mps_dimension_dungeon_piece_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &total_amount);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
