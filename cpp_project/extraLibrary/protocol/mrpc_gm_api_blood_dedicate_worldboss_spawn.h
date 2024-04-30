#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_api_blood_dedicate_worldboss_spawn_cs : public RpcPacket 
	{
	public:
		int32_t world_gid{};	// 월드 gid

	public:
		mrpc_gm_api_blood_dedicate_worldboss_spawn_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_api_blood_dedicate_worldboss_spawn_cs, tag)
		{
		}
		mrpc_gm_api_blood_dedicate_worldboss_spawn_cs() : RpcPacket(mpe_rpc_cmd::gm_api_blood_dedicate_worldboss_spawn_cs)
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

	class mrpc_gm_api_blood_dedicate_worldboss_spawn_sc : public RpcPacket 
	{

	public:
		mrpc_gm_api_blood_dedicate_worldboss_spawn_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_api_blood_dedicate_worldboss_spawn_sc, tag)
		{
		}
		mrpc_gm_api_blood_dedicate_worldboss_spawn_sc() : RpcPacket(mpe_rpc_cmd::gm_api_blood_dedicate_worldboss_spawn_sc)
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
