#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_alert_end_war_cs : public BasePacket 	// // 전쟁 종료 알림 패킷
	{

	public:
		mp_guild_alert_end_war_cs() : BasePacket(mpe_cmd::guild_alert_end_war_cs)
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

	class mp_guild_alert_end_war_sc : public BasePacket 	// // 전쟁 종료 알림 패킷
	{
	public:
		int64_t winner_guid{};	// // 전쟁 선포한 길드ID
	public:
		int64_t loser_guid{};	// // 전쟁 선포당한 길드ID
	public:
		std::string winner_guild_name{};	// // 전쟁 선포한 길드명
	public:
		std::string loser_guild_name{};	// // 전쟁 선포당한 길드명
	public:
		int64_t next_available_start_time{};
	public:
		int32_t nego_gold{};

	public:
		mp_guild_alert_end_war_sc() : BasePacket(mpe_cmd::guild_alert_end_war_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &winner_guid);
			protocol::SerializeType(pBuffer, &loser_guid);
			protocol::SerializeType(pBuffer, &winner_guild_name);
			protocol::SerializeType(pBuffer, &loser_guild_name);
			protocol::SerializeType(pBuffer, &next_available_start_time);
			protocol::SerializeType(pBuffer, &nego_gold);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
