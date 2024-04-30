#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mrpc_vehicle_food_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_item_count_update> update_item{};	// 아이템 사용정보
	public:
		int32_t vehicle_id{};
	public:
		int32_t satiety{};
	public:
		int32_t level{};
	public:
		int32_t exp{};

	public:
		mrpc_vehicle_food_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::vehicle_food_cs, tag)
		{
		}
		mrpc_vehicle_food_cs() : RpcPacket(mpe_rpc_cmd::vehicle_food_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &update_item);
			protocol::SerializeType(pBuffer, &vehicle_id);
			protocol::SerializeType(pBuffer, &satiety);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &exp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_vehicle_food_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_vehicle_food_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::vehicle_food_sc, tag)
		{
		}
		mrpc_vehicle_food_sc() : RpcPacket(mpe_rpc_cmd::vehicle_food_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
