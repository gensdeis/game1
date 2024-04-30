#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_blood_dedicate_worldboss_summon_state_cs : public RpcPacket 
	{

	public:
		mrpc_blood_dedicate_worldboss_summon_state_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blood_dedicate_worldboss_summon_state_cs, tag)
		{
		}
		mrpc_blood_dedicate_worldboss_summon_state_cs() : RpcPacket(mpe_rpc_cmd::blood_dedicate_worldboss_summon_state_cs)
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

	class mrpc_blood_dedicate_worldboss_summon_state_sc : public RpcPacket 
	{
	public:
		mpe_blood_dedicate_worldboss_state worldboss_state{};	// 보스 상태

	public:
		mrpc_blood_dedicate_worldboss_summon_state_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blood_dedicate_worldboss_summon_state_sc, tag)
		{
		}
		mrpc_blood_dedicate_worldboss_summon_state_sc() : RpcPacket(mpe_rpc_cmd::blood_dedicate_worldboss_summon_state_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &worldboss_state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
