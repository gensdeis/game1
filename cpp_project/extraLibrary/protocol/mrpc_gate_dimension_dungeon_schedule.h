#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_dimension_dungeon_schedule_cs : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gate_dimension_dungeon_schedule_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_dimension_dungeon_schedule_cs, tag)
		{
		}
		mrpc_gate_dimension_dungeon_schedule_cs() : RpcPacket(mpe_rpc_cmd::gate_dimension_dungeon_schedule_cs)
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

	class mrpc_gate_dimension_dungeon_schedule_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		mpe_dimension_dungeon_schedule_type type{};	// 현재 차원비경 스케쥴
	public:
		int32_t start_remain_sec{};	// 차원비경 시작까지 남은 초. pre_open 일때만 유효.

	public:
		mrpc_gate_dimension_dungeon_schedule_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_dimension_dungeon_schedule_sc, tag)
		{
		}
		mrpc_gate_dimension_dungeon_schedule_sc() : RpcPacket(mpe_rpc_cmd::gate_dimension_dungeon_schedule_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &start_remain_sec);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
