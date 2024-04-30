#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_dimension_dungeon_contribution_status.h"

namespace mir3d
{
	class mrpc_dimension_dungeon_state_cs : public RpcPacket 
	{

	public:
		mrpc_dimension_dungeon_state_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dimension_dungeon_state_cs, tag)
		{
		}
		mrpc_dimension_dungeon_state_cs() : RpcPacket(mpe_rpc_cmd::dimension_dungeon_state_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_dimension_dungeon_state_sc : public RpcPacket 
	{
	public:
		mpe_dimension_dungeon_schedule_type state{};	// 차원비경의 상태
	public:
		int32_t start_timestamp{};	// 차원비경의 시작 시간 (epoch time second)
	public:
		int32_t end_timestamp{};	// 차원비경의 종료 시간 (epoch time second)
	public:
		std::vector<mrpcs_dimension_dungeon_contribution_status> contribution_status{};	// 각 World Game Server별 차원 조각 수급량 정보
	public:
		int64_t _uid{};	// World Game 서버 내 로직을 위한 값으로 World Game Manager에서는 무시 또는 0 할당

	public:
		mrpc_dimension_dungeon_state_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dimension_dungeon_state_sc, tag)
		{
		}
		mrpc_dimension_dungeon_state_sc() : RpcPacket(mpe_rpc_cmd::dimension_dungeon_state_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &start_timestamp);
			protocol::SerializeType(pBuffer, &end_timestamp);
			protocol::SerializeType(pBuffer, &contribution_status);
			protocol::SerializeType(pBuffer, &_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
