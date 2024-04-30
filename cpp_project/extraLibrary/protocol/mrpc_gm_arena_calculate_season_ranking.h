#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_arena_calculate_season_ranking_cs : public RpcPacket 
	{

	public:
		mrpc_gm_arena_calculate_season_ranking_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_arena_calculate_season_ranking_cs, tag)
		{
		}
		mrpc_gm_arena_calculate_season_ranking_cs() : RpcPacket(mpe_rpc_cmd::gm_arena_calculate_season_ranking_cs)
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

	class mrpc_gm_arena_calculate_season_ranking_sc : public RpcPacket 
	{

	public:
		mrpc_gm_arena_calculate_season_ranking_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_arena_calculate_season_ranking_sc, tag)
		{
		}
		mrpc_gm_arena_calculate_season_ranking_sc() : RpcPacket(mpe_rpc_cmd::gm_arena_calculate_season_ranking_sc)
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
