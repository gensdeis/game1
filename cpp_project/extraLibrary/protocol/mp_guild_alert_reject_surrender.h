#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_alert_reject_surrender_cs : public BasePacket 	// // 항복 수락 거절 알림 패킷
	{

	public:
		mp_guild_alert_reject_surrender_cs() : BasePacket(mpe_cmd::guild_alert_reject_surrender_cs)
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

	class mp_guild_alert_reject_surrender_sc : public BasePacket 	// // 항복 수락 거절 알림 패킷
	{
	public:
		int64_t winner_guid{};	// // 거절한 문파 id
	public:
		int64_t loser_guid{};	// // 거절당한 문파 id
	public:
		std::string winner_guild_name{};	// // 거절한 문파명
	public:
		std::string loser_guild_name{};	// // 거절당한 문파명
	public:
		int32_t reject_count{};	// // 거절 횟수
	public:
		int32_t negotiation_gold{};	// // 돌려받은 협상금

	public:
		mp_guild_alert_reject_surrender_sc() : BasePacket(mpe_cmd::guild_alert_reject_surrender_sc)
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
			protocol::SerializeType(pBuffer, &reject_count);
			protocol::SerializeType(pBuffer, &negotiation_gold);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
