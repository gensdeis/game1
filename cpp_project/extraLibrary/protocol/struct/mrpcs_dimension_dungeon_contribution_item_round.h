#pragma once
#include <vector>
#include <string>
#include "mrpcs_dimension_dungeon_contribution_item.h"

namespace mir3d
{
	class mrpcs_dimension_dungeon_contribution_item_round 	// 회차별 차원비경 기여도랭킹 관련 조각수급량
	{
	public:
		std::vector<mrpcs_dimension_dungeon_contribution_item> item_list{};	// game서버 gid 별 차원조각 수급량 정보
	public:
		int32_t round{};	// 회차 아이디

	public:
		mrpcs_dimension_dungeon_contribution_item_round()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &item_list);
			protocol::SerializeType(pBuffer, &round);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
