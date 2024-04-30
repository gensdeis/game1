#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_arena_battle_match_regist_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t power{};
	public:
		int32_t gid{};

	public:
		mrpc_arena_battle_match_regist_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::arena_battle_match_regist_cs, tag)
		{
		}
		mrpc_arena_battle_match_regist_cs() : RpcPacket(mpe_rpc_cmd::arena_battle_match_regist_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &power);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_arena_battle_match_regist_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_arena_battle_match_regist_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::arena_battle_match_regist_sc, tag)
		{
		}
		mrpc_arena_battle_match_regist_sc() : RpcPacket(mpe_rpc_cmd::arena_battle_match_regist_sc)
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

}
