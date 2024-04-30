#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_teleport_area 	// 텔레포트 좌표 저장
	{
	public:
		int32_t map_id{};	// 맵아이디
	public:
		int32_t tile_index{};	// 셀인덱스

	public:
		mps_teleport_area()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &map_id);
			protocol::SerializeType(pBuffer, &tile_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
