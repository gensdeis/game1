#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_change_occupation_war_state_cs : public RpcPacket 	// 비곡점령전 상태 변경 ( 월드 전체 적용 )
	{
	public:
		mrpce_occupationwar_war_schedule_noti_type state{};	// 변경할 상태

	public:
		mrpc_gm_change_occupation_war_state_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_change_occupation_war_state_cs, tag)
		{
		}
		mrpc_gm_change_occupation_war_state_cs() : RpcPacket(mpe_rpc_cmd::gm_change_occupation_war_state_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_change_occupation_war_state_sc : public RpcPacket 	// 비곡점령전 상태 변경 ( 월드 전체 적용 )
	{

	public:
		mrpc_gm_change_occupation_war_state_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_change_occupation_war_state_sc, tag)
		{
		}
		mrpc_gm_change_occupation_war_state_sc() : RpcPacket(mpe_rpc_cmd::gm_change_occupation_war_state_sc)
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

}
