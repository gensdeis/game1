#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_party_leave_alert_by_indun_kick_cs : public BasePacket 
	{

	public:
		mp_party_leave_alert_by_indun_kick_cs() : BasePacket(mpe_cmd::party_leave_alert_by_indun_kick_cs)
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

	class mp_party_leave_alert_by_indun_kick_sc : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		mpe_error reason{};	// "킥 사유. mpe_error 메세지."

	public:
		mp_party_leave_alert_by_indun_kick_sc() : BasePacket(mpe_cmd::party_leave_alert_by_indun_kick_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &reason);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
