#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mp_vehicle_food_cs : public BasePacket 
	{
	public:
		int32_t food_tid{};	// 먹이
	public:
		mpe_vehicle_food_use use_type{};	// 사용 타입
	public:
		int32_t vehicle_tid{};	// 탈것
	public:
		std::vector<int32_t> list_tid{};

	public:
		mp_vehicle_food_cs() : BasePacket(mpe_cmd::vehicle_food_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &food_tid);
			protocol::SerializeEnum(pBuffer, &use_type);
			protocol::SerializeType(pBuffer, &vehicle_tid);
			protocol::SerializeType(pBuffer, &list_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_vehicle_food_sc : public BasePacket 
	{
	public:
		int32_t vehicle_tid{};
	public:
		std::vector<mps_item_count_update> update_item{};	// 사용한 아이템
	public:
		int32_t satiety{};	// 적용된 만복도
	public:
		int32_t level{};
	public:
		int32_t exp{};

	public:
		mp_vehicle_food_sc() : BasePacket(mpe_cmd::vehicle_food_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &vehicle_tid);
			protocol::SerializeType(pBuffer, &update_item);
			protocol::SerializeType(pBuffer, &satiety);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &exp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
