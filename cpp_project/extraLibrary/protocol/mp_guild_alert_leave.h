#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_alert_leave_cs : public BasePacket 	// // 문파탈퇴 알림 패킷 (남은 문파원)
	{

	public:
		mp_guild_alert_leave_cs() : BasePacket(mpe_cmd::guild_alert_leave_cs)
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

	class mp_guild_alert_leave_sc : public BasePacket 	// // 문파탈퇴 알림 패킷 (남은 문파원)
	{
	public:
		int64_t leave_member_cuid{};	// // 탈퇴한 유저ID
	public:
		std::string leave_member_name{};	// // 탈퇴 유저명

	public:
		mp_guild_alert_leave_sc() : BasePacket(mpe_cmd::guild_alert_leave_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &leave_member_cuid);
			protocol::SerializeType(pBuffer, &leave_member_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
