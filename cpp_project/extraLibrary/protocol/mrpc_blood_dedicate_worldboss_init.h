#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_blood_dedicate_worldboss_init_cs : public RpcPacket 
	{
	public:
		int32_t zone_id{};	// 월드보스 소환 맵 아이디
	public:
		int32_t monster_id{};	// 소환된 월드보스 아이디

	public:
		mrpc_blood_dedicate_worldboss_init_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blood_dedicate_worldboss_init_cs, tag)
		{
		}
		mrpc_blood_dedicate_worldboss_init_cs() : RpcPacket(mpe_rpc_cmd::blood_dedicate_worldboss_init_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &monster_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_blood_dedicate_worldboss_init_sc : public RpcPacket 
	{

	public:
		mrpc_blood_dedicate_worldboss_init_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blood_dedicate_worldboss_init_sc, tag)
		{
		}
		mrpc_blood_dedicate_worldboss_init_sc() : RpcPacket(mpe_rpc_cmd::blood_dedicate_worldboss_init_sc)
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
