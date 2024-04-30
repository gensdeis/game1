#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_decrement_item_durability 	// 아이템 내구도 감소 
	{
	public:
		int64_t iuid{};
	public:
		mpe_equip_pos pos{};	// 장비착용위치
	public:
		int32_t dec_val{};	// 내구도 감소값
	public:
		mpe_item_durability_decrement_type decrement_type{};	// 내구도 감소 타입(이유)

	public:
		mps_decrement_item_durability()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &dec_val);
			protocol::SerializeEnum(pBuffer, &decrement_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
