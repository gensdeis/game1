#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_game_world_boss_spawn_cs : public RpcPacket 	// 월드 보스 레이드 스폰 정보
	{

	public:
		mrpc_game_world_boss_spawn_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::game_world_boss_spawn_cs, tag)
		{
		}
		mrpc_game_world_boss_spawn_cs() : RpcPacket(mpe_rpc_cmd::game_world_boss_spawn_cs)
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

	class mrpc_game_world_boss_spawn_sc : public RpcPacket 	// 월드 보스 레이드 스폰 정보
	{
	public:
		int32_t zone_id{};	// 맵 id
	public:
		int32_t tid{};	// 월드 보스 레이드 테이블 아이디
	public:
		int64_t channel_uid{};

	public:
		mrpc_game_world_boss_spawn_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::game_world_boss_spawn_sc, tag)
		{
		}
		mrpc_game_world_boss_spawn_sc() : RpcPacket(mpe_rpc_cmd::game_world_boss_spawn_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &channel_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
