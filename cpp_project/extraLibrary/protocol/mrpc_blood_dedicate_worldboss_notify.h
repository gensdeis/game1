#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_blood_dedicate_worldboss_notify_cs : public RpcPacket 	// 봉혈 보스소환 및 사망 및 도주시 클라에 전달하는 메시지
	{
	public:
		mpe_blood_dedicate_worldboss_state worldboss_state{};	// 보스상태

	public:
		mrpc_blood_dedicate_worldboss_notify_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blood_dedicate_worldboss_notify_cs, tag)
		{
		}
		mrpc_blood_dedicate_worldboss_notify_cs() : RpcPacket(mpe_rpc_cmd::blood_dedicate_worldboss_notify_cs)
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

	class mrpc_blood_dedicate_worldboss_notify_sc : public RpcPacket 	// 봉혈 보스소환 및 사망 및 도주시 클라에 전달하는 메시지
	{
	public:
		mpe_blood_dedicate_worldboss_state worldboss_state{};	// 보스상태
	public:
		int32_t map_tag{};	// zone 스레드 인덱스

	public:
		mrpc_blood_dedicate_worldboss_notify_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blood_dedicate_worldboss_notify_sc, tag)
		{
		}
		mrpc_blood_dedicate_worldboss_notify_sc() : RpcPacket(mpe_rpc_cmd::blood_dedicate_worldboss_notify_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &worldboss_state);
			protocol::SerializeType(pBuffer, &map_tag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
