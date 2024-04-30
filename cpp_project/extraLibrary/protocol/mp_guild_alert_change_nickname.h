#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_alert_change_nickname_cs : public BasePacket 	// // 문파원 닉네임 변경 알림 패킷
	{

	public:
		mp_guild_alert_change_nickname_cs() : BasePacket(mpe_cmd::guild_alert_change_nickname_cs)
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

	class mp_guild_alert_change_nickname_sc : public BasePacket 	// // 문파원 닉네임 변경 알림 패킷
	{
	public:
		int64_t change_member_cuid{};	// // 변경된 유저ID
	public:
		std::string change_member_name{};	// // 변경된 유저명

	public:
		mp_guild_alert_change_nickname_sc() : BasePacket(mpe_cmd::guild_alert_change_nickname_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &change_member_cuid);
			protocol::SerializeType(pBuffer, &change_member_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
