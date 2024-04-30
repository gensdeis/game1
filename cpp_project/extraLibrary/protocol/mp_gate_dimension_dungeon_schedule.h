#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_dimension_dungeon_schedule_cs : public BasePacket 
	{

	public:
		mp_gate_dimension_dungeon_schedule_cs() : BasePacket(mpe_cmd::gate_dimension_dungeon_schedule_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_dimension_dungeon_schedule_sc : public BasePacket 
	{
	public:
		mpe_dimension_dungeon_schedule_type type{};	// 현재 차원비경 스케쥴
	public:
		int32_t start_remain_sec{};	// 차원비경 시작까지 남은 초. pre_open 일때만 유효.

	public:
		mp_gate_dimension_dungeon_schedule_sc() : BasePacket(mpe_cmd::gate_dimension_dungeon_schedule_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &start_remain_sec);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
