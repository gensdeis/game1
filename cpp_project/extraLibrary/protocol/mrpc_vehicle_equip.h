#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_vehicle_equip_cs : public RpcPacket 	// 탈것 장착
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t vehicle_tid{};	// 변경된 탈것
	public:
		int32_t change_tid{};	// 이전 장착 탈것 tid
	public:
		int32_t satiety{};	// 이전 장착된 탈것 만복도 저장

	public:
		mrpc_vehicle_equip_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::vehicle_equip_cs, tag)
		{
		}
		mrpc_vehicle_equip_cs() : RpcPacket(mpe_rpc_cmd::vehicle_equip_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &vehicle_tid);
			protocol::SerializeType(pBuffer, &change_tid);
			protocol::SerializeType(pBuffer, &satiety);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_vehicle_equip_sc : public RpcPacket 	// 탈것 장착
	{
	public:
		int64_t key{};

	public:
		mrpc_vehicle_equip_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::vehicle_equip_sc, tag)
		{
		}
		mrpc_vehicle_equip_sc() : RpcPacket(mpe_rpc_cmd::vehicle_equip_sc)
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
