#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_ally_alert_cs : public BasePacket 	// "길드동맹알림"
	{

	public:
		mp_guild_ally_alert_cs() : BasePacket(mpe_cmd::guild_ally_alert_cs)
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

	class mp_guild_ally_alert_sc : public BasePacket 	// "길드동맹알림"
	{
	public:
		mpe_guild_ally_alert_type type{};	// "알림타입"
	public:
		std::string target_guild_name{};	// "길드이름"
	public:
		int64_t target_guid{};	// "대상길드uid"
	public:
		int64_t master_cuid{};	// "대상문주cuid"
	public:
		int64_t submaster_cuid{};	// "대상부분주cuid"
	public:
		uint8_t slot{};	// "대상길드슬롯번호 동맹상태 일때만 유효."

	public:
		mp_guild_ally_alert_sc() : BasePacket(mpe_cmd::guild_ally_alert_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &target_guild_name);
			protocol::SerializeType(pBuffer, &target_guid);
			protocol::SerializeType(pBuffer, &master_cuid);
			protocol::SerializeType(pBuffer, &submaster_cuid);
			protocol::SerializeType(pBuffer, &slot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
