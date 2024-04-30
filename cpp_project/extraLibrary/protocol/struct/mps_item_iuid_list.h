#pragma once
#include <vector>
#include <string>
#include "mps_item_iuid.h"

namespace mir3d
{
	class mps_item_iuid_list 
	{
	public:
		std::vector<mps_item_iuid> list{};

	public:
		mps_item_iuid_list()
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
