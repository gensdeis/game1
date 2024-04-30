#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_blood_dedicate_worldboss_notify_cs : public BasePacket 	// 봉혈 보스소환 및 사망 및 도주시 클라에 전달하는 메시지
	{

	public:
		mp_blood_dedicate_worldboss_notify_cs() : BasePacket(mpe_cmd::blood_dedicate_worldboss_notify_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_blood_dedicate_worldboss_notify_sc : public BasePacket 	// 봉혈 보스소환 및 사망 및 도주시 클라에 전달하는 메시지
	{
	public:
		mpe_blood_dedicate_worldboss_state worldboss_state{};	// 보스상태

	public:
		mp_blood_dedicate_worldboss_notify_sc() : BasePacket(mpe_cmd::blood_dedicate_worldboss_notify_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &worldboss_state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
