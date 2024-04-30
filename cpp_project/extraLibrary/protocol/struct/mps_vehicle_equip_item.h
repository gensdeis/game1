#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_vehicle_equip_item 
	{
	public:
		mpe_equip_pos pos{};	// "이동된 장비 위치(탈것,인벤=>max)"
	public:
		int64_t iuid{};
	public:
		int32_t equip_index{};	// 장착시 장비의 위치

	public:
		mps_vehicle_equip_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &equip_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
