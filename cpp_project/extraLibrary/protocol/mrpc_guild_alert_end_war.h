#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_alert_end_war_cs : public RpcPacket 	// // 전쟁 종료 알림 패킷
	{

	public:
		mrpc_guild_alert_end_war_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_end_war_cs, tag)
		{
		}
		mrpc_guild_alert_end_war_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_end_war_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_alert_end_war_sc : public RpcPacket 	// // 전쟁 종료 알림 패킷
	{
	public:
		std::vector<int64_t> list_cuid{};	// // 패킷받아야할 대상
	public:
		int64_t winner_guid{};	// // 승리 문파 ID
	public:
		int64_t loser_guid{};	// // 패배 문파 ID
	public:
		std::string winner_guild_name{};	// // 승리 문파명
	public:
		std::string loser_guild_name{};	// // 패배 문파명
	public:
		int64_t next_available_start_time{};	// // 다음 전쟁 선포가능 시간 (초)
	public:
		int32_t nego_gold{};

	public:
		mrpc_guild_alert_end_war_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_end_war_sc, tag)
		{
		}
		mrpc_guild_alert_end_war_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_end_war_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &winner_guid);
			protocol::SerializeType(pBuffer, &loser_guid);
			protocol::SerializeType(pBuffer, &winner_guild_name);
			protocol::SerializeType(pBuffer, &loser_guild_name);
			protocol::SerializeType(pBuffer, &next_available_start_time);
			protocol::SerializeType(pBuffer, &nego_gold);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
