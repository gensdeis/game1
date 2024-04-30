#pragma once
#include <vector>
#include <string>
#include "mps_drop_item_info.h"

namespace mir3d
{
	class mps_zone_drop_item_info 
	{
	public:
		std::vector<mps_drop_item_info> info{};	// 드랍리스트정보
	public:
		int64_t create_time{};	// 생성시간
	public:
		mpe_drop_owner owner_type{};	// 드랍아이템소유권체크타입

	public:
		mps_zone_drop_item_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &create_time);
			protocol::SerializeEnum(pBuffer, &owner_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
