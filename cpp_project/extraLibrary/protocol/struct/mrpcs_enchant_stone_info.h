#pragma once
#include <vector>
#include <string>
#include "mrpcs_item_stone_pair.h"

namespace mir3d
{
	class mrpcs_enchant_stone_info 
	{
	public:
		std::vector<mrpcs_item_stone_pair> pair_info{};	// 아이템과 용령석 매칭 정보

	public:
		mrpcs_enchant_stone_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &pair_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
