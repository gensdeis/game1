#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_boss_governance_spawn_cs : public RpcPacket 
	{
	public:
		int32_t type{};	// 0 : field  1 : world
	public:
		int32_t zone_id{};
	public:
		int32_t monster_id{};

	public:
		mrpc_gm_boss_governance_spawn_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_boss_governance_spawn_cs, tag)
		{
		}
		mrpc_gm_boss_governance_spawn_cs() : RpcPacket(mpe_rpc_cmd::gm_boss_governance_spawn_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &monster_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_boss_governance_spawn_sc : public RpcPacket 
	{
	public:
		int32_t type{};	// 0 : field  1 : world
	public:
		int32_t zone_id{};
	public:
		int32_t monster_id{};

	public:
		mrpc_gm_boss_governance_spawn_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_boss_governance_spawn_sc, tag)
		{
		}
		mrpc_gm_boss_governance_spawn_sc() : RpcPacket(mpe_rpc_cmd::gm_boss_governance_spawn_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &monster_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
