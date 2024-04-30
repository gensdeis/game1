#pragma once
#include <vector>
#include <string>
#include "mps_item_count_update.h"
#include "mps_item.h"

namespace mir3d
{
	class mps_item_update 
	{
	public:
		std::vector<mps_item_count_update> list_update{};
	public:
		std::vector<mps_item> list_item{};

	public:
		mps_item_update()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list_update);
			protocol::SerializeType(pBuffer, &list_item);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
