#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_town_building_info 	// 장원 건물 정보
	{
	public:
		bool build{};	// 고용여부
	public:
		int32_t level{};	// 레벨

	public:
		mps_castle_town_building_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &build);
			protocol::SerializeType(pBuffer, &level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
