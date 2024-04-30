#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_arena_character.h"

namespace mir3d
{
	class mrpc_arena_battle_result_cs : public RpcPacket 
	{
	public:
		std::vector<mps_arena_character> list_arena_character{};
	public:
		int64_t indun_uid{};

	public:
		mrpc_arena_battle_result_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::arena_battle_result_cs, tag)
		{
		}
		mrpc_arena_battle_result_cs() : RpcPacket(mpe_rpc_cmd::arena_battle_result_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_arena_character);
			protocol::SerializeType(pBuffer, &indun_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_arena_battle_result_sc : public RpcPacket 
	{

	public:
		mrpc_arena_battle_result_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::arena_battle_result_sc, tag)
		{
		}
		mrpc_arena_battle_result_sc() : RpcPacket(mpe_rpc_cmd::arena_battle_result_sc)
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
