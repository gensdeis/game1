#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_arena_battle_add_score_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t add_score{};
	public:
		int32_t class_type{};
	public:
		uint8_t is_join_count{};	// 참여횟수차감 여부 (0:차감x 1:차감o)
	public:
		int32_t gid{};

	public:
		mrpc_arena_battle_add_score_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::arena_battle_add_score_cs, tag)
		{
		}
		mrpc_arena_battle_add_score_cs() : RpcPacket(mpe_rpc_cmd::arena_battle_add_score_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &add_score);
			protocol::SerializeType(pBuffer, &class_type);
			protocol::SerializeType(pBuffer, &is_join_count);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_arena_battle_add_score_sc : public RpcPacket 
	{

	public:
		mrpc_arena_battle_add_score_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::arena_battle_add_score_sc, tag)
		{
		}
		mrpc_arena_battle_add_score_sc() : RpcPacket(mpe_rpc_cmd::arena_battle_add_score_sc)
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
