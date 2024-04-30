#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_member_pk_death_alert_cs : public BasePacket 	// "길드원이 pk 사망함 알림 파라메터 없음."
	{

	public:
		mp_guild_member_pk_death_alert_cs() : BasePacket(mpe_cmd::guild_member_pk_death_alert_cs)
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

	class mp_guild_member_pk_death_alert_sc : public BasePacket 	// "길드원이 pk 사망함 알림 파라메터 없음."
	{

	public:
		mp_guild_member_pk_death_alert_sc() : BasePacket(mpe_cmd::guild_member_pk_death_alert_sc)
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

}
