#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_siege_warfare_alert_cs : public BasePacket 	// 공성전 정보 알림
	{

	public:
		mp_siege_warfare_alert_cs() : BasePacket(mpe_cmd::siege_warfare_alert_cs)
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

	class mp_siege_warfare_alert_sc : public BasePacket 	// 공성전 정보 알림
	{
	public:
		int64_t alert_guid{};	// 보낸길드
	public:
		std::string alert_guild_name{};	// 보낸길드이름
	public:
		mpe_siege_alert_type alert_type{};	// 알림 타입

	public:
		mp_siege_warfare_alert_sc() : BasePacket(mpe_cmd::siege_warfare_alert_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &alert_guid);
			protocol::SerializeType(pBuffer, &alert_guild_name);
			protocol::SerializeEnum(pBuffer, &alert_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
