#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_world_arena_team.h"
#include "struct/mrpcs_world_arena_team.h"
#include "struct/mrpcs_world_arena_team.h"
#include "struct/mrpcs_world_arena_team.h"

namespace mir3d
{
	class mrpc_arena_battle_create_cs : public RpcPacket 
	{
	public:
		int32_t tid{};	// indun table id
	public:
		std::vector<mrpcs_world_arena_team> a_team{};	// a_team 유저들 cuid
	public:
		std::vector<mrpcs_world_arena_team> b_team{};	// b_team 유저들 cuid

	public:
		mrpc_arena_battle_create_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::arena_battle_create_cs, tag)
		{
		}
		mrpc_arena_battle_create_cs() : RpcPacket(mpe_rpc_cmd::arena_battle_create_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &a_team);
			protocol::SerializeType(pBuffer, &b_team);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_arena_battle_create_sc : public RpcPacket 
	{
	public:
		int32_t tid{};	// indun table id
	public:
		int64_t cuid{};	// target cuid
	public:
		std::vector<mrpcs_world_arena_team> a_team{};	// a_team 유저들 cuid
	public:
		std::vector<mrpcs_world_arena_team> b_team{};	// b_team 유저들 cuid
	public:
		int32_t gid{};	// indun server gid
	public:
		int32_t index{};	// // indun server index
	public:
		int64_t indun_uid{};

	public:
		mrpc_arena_battle_create_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::arena_battle_create_sc, tag)
		{
		}
		mrpc_arena_battle_create_sc() : RpcPacket(mpe_rpc_cmd::arena_battle_create_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &a_team);
			protocol::SerializeType(pBuffer, &b_team);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &indun_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
