#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_arena_battle_start_cs : public RpcPacket 
	{
	public:
		int32_t tid{};
	public:
		int32_t match_count{};

	public:
		mrpc_gm_arena_battle_start_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_arena_battle_start_cs, tag)
		{
		}
		mrpc_gm_arena_battle_start_cs() : RpcPacket(mpe_rpc_cmd::gm_arena_battle_start_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &match_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_arena_battle_start_sc : public RpcPacket 
	{

	public:
		mrpc_gm_arena_battle_start_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_arena_battle_start_sc, tag)
		{
		}
		mrpc_gm_arena_battle_start_sc() : RpcPacket(mpe_rpc_cmd::gm_arena_battle_start_sc)
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
