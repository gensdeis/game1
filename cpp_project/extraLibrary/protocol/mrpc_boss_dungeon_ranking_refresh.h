#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_boss_dungeon_ranking_refresh_cs : public RpcPacket 
	{

	public:
		mrpc_boss_dungeon_ranking_refresh_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::boss_dungeon_ranking_refresh_cs, tag)
		{
		}
		mrpc_boss_dungeon_ranking_refresh_cs() : RpcPacket(mpe_rpc_cmd::boss_dungeon_ranking_refresh_cs)
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

	class mrpc_boss_dungeon_ranking_refresh_sc : public RpcPacket 
	{

	public:
		mrpc_boss_dungeon_ranking_refresh_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::boss_dungeon_ranking_refresh_sc, tag)
		{
		}
		mrpc_boss_dungeon_ranking_refresh_sc() : RpcPacket(mpe_rpc_cmd::boss_dungeon_ranking_refresh_sc)
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
