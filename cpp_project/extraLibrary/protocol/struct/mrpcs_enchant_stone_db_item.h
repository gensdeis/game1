#pragma once
#include <vector>
#include <string>
#include "mps_item_count_update.h"
#include "mrpcs_enchant_stone_update_pos.h"
#include "mps_update_goods.h"

namespace mir3d
{
	class mrpcs_enchant_stone_db_item 
	{
	public:
		std::vector<mps_item_count_update> update_item{};	// 사용한 재료 아이템 update
	public:
		std::vector<mrpcs_enchant_stone_update_pos> update_stone{};	// 용령석 착용/해제 위치
	public:
		std::vector<mps_update_goods> update_goods{};	// 사용한 재화

	public:
		mrpcs_enchant_stone_db_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &update_item);
			protocol::SerializeType(pBuffer, &update_stone);
			protocol::SerializeType(pBuffer, &update_goods);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
