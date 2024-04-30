#pragma once
#include <vector>
#include <string>
#include "mps_update_goods.h"

namespace mir3d
{
	class mps_update_goods_list 
	{
	public:
		std::vector<mps_update_goods> list_goods{};	// //변경된재화

	public:
		mps_update_goods_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list_goods);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
