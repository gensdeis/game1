#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_alert_ban_cs : public BasePacket 	// // 문파 추방 알림 패킷 (추방된 문파원)
	{

	public:
		mp_guild_alert_ban_cs() : BasePacket(mpe_cmd::guild_alert_ban_cs)
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

	class mp_guild_alert_ban_sc : public BasePacket 	// // 문파 추방 알림 패킷 (추방된 문파원)
	{
	public:
		int64_t next_available_join_time{};	// // 다음 문파 가입 가능 시간

	public:
		mp_guild_alert_ban_sc() : BasePacket(mpe_cmd::guild_alert_ban_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &next_available_join_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
