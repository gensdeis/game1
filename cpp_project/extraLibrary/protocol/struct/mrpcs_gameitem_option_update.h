#pragma once
#include <vector>
#include <string>
#include "mrpcs_item_stone_pair.h"

namespace mir3d
{
	class mrpcs_gameitem_option_update 
	{
	public:
		int64_t cuid{};
	public:
		std::vector<mrpcs_item_stone_pair> info{};

	public:
		mrpcs_gameitem_option_update()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
