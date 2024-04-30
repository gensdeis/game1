#pragma once
#include <vector>
#include <string>
#include "mps_item_pickup_info.h"

namespace mir3d
{
	class mps_item_pickup 	// 아이템획득
	{
	public:
		int64_t uid{};	// 가방 object uid
	public:
		std::vector<mps_item_pickup_info> info{};	// 아이템정보

	public:
		mps_item_pickup()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
