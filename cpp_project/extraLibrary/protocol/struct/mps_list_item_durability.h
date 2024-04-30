#pragma once
#include <vector>
#include <string>
#include "mps_item_durability.h"

namespace mir3d
{
	class mps_list_item_durability 	// 아이템 내구도 저장을 위한 리스트
	{
	public:
		std::vector<mps_item_durability> list{};

	public:
		mps_list_item_durability()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
