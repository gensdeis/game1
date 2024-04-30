#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_dimension_dungeon_contribution.h"

namespace mir3d
{
	class mrpc_dimension_dungeon_contribution_daily_reset_cs : public RpcPacket 
	{

	public:
		mrpc_dimension_dungeon_contribution_daily_reset_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_daily_reset_cs, tag)
		{
		}
		mrpc_dimension_dungeon_contribution_daily_reset_cs() : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_daily_reset_cs)
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

	class mrpc_dimension_dungeon_contribution_daily_reset_sc : public RpcPacket 
	{
	public:
		std::vector<mrpcs_dimension_dungeon_contribution> contribution_info_list{};	// 기여도관련 정보

	public:
		mrpc_dimension_dungeon_contribution_daily_reset_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_daily_reset_sc, tag)
		{
		}
		mrpc_dimension_dungeon_contribution_daily_reset_sc() : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_daily_reset_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &contribution_info_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
