#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_indun_monarch_state_alert_cs : public BasePacket 	// 플레이 시작/상태
	{

	public:
		mp_indun_monarch_state_alert_cs() : BasePacket(mpe_cmd::indun_monarch_state_alert_cs)
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

	class mp_indun_monarch_state_alert_sc : public BasePacket 	// 플레이 시작/상태
	{
	public:
		mpe_indun_monarch_state state{};	// 플레이 상태

	public:
		mp_indun_monarch_state_alert_sc() : BasePacket(mpe_cmd::indun_monarch_state_alert_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
