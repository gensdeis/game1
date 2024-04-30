#pragma once
#include <vector>
#include <string>
#include "mrpcs_dimension_dungeon_contribution_item.h"

namespace mir3d
{
	class mrpcs_dimension_dungeon_contribution_status 	// World Game 서버의 차원비경 차원조각 수급량 정보
	{
	public:
		int32_t index{};	// World Game 서버의 index
	public:
		std::vector<mrpcs_dimension_dungeon_contribution_item> item_list{};	// World Game 서버의 각 gid별 차원조각 수급량 정보

	public:
		mrpcs_dimension_dungeon_contribution_status()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &item_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
