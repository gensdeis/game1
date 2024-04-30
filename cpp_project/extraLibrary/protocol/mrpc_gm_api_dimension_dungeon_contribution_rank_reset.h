#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_api_dimension_dungeon_contribution_rank_reset_cs : public RpcPacket 
	{
	public:
		int32_t world_gid{};	// 월드 gid

	public:
		mrpc_gm_api_dimension_dungeon_contribution_rank_reset_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_api_dimension_dungeon_contribution_rank_reset_cs, tag)
		{
		}
		mrpc_gm_api_dimension_dungeon_contribution_rank_reset_cs() : RpcPacket(mpe_rpc_cmd::gm_api_dimension_dungeon_contribution_rank_reset_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &world_gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_api_dimension_dungeon_contribution_rank_reset_sc : public RpcPacket 
	{

	public:
		mrpc_gm_api_dimension_dungeon_contribution_rank_reset_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_api_dimension_dungeon_contribution_rank_reset_sc, tag)
		{
		}
		mrpc_gm_api_dimension_dungeon_contribution_rank_reset_sc() : RpcPacket(mpe_rpc_cmd::gm_api_dimension_dungeon_contribution_rank_reset_sc)
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
