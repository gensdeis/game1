#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_alert_ban_for_member_cs : public BasePacket 	// // 문파 추방 알림 패킷 (남은 문파원)
	{

	public:
		mp_guild_alert_ban_for_member_cs() : BasePacket(mpe_cmd::guild_alert_ban_for_member_cs)
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

	class mp_guild_alert_ban_for_member_sc : public BasePacket 	// // 문파 추방 알림 패킷 (남은 문파원)
	{
	public:
		int64_t ban_member_cuid{};	// // 추방된 유저ID
	public:
		std::string ban_member_name{};	// // 추방된 유저명

	public:
		mp_guild_alert_ban_for_member_sc() : BasePacket(mpe_cmd::guild_alert_ban_for_member_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ban_member_cuid);
			protocol::SerializeType(pBuffer, &ban_member_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
