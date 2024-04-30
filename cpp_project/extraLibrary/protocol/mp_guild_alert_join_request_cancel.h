#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_alert_join_request_cancel_cs : public BasePacket 	// // 가입요청 취소 알림 패킷
	{

	public:
		mp_guild_alert_join_request_cancel_cs() : BasePacket(mpe_cmd::guild_alert_join_request_cancel_cs)
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

	class mp_guild_alert_join_request_cancel_sc : public BasePacket 	// // 가입요청 취소 알림 패킷
	{
	public:
		int64_t request_cuid{};	// // 가입요청한 유저 id

	public:
		mp_guild_alert_join_request_cancel_sc() : BasePacket(mpe_cmd::guild_alert_join_request_cancel_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &request_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
