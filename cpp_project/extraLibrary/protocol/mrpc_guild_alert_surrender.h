#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_alert_surrender_cs : public RpcPacket 	// // 항복 알림 패킷
	{

	public:
		mrpc_guild_alert_surrender_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_surrender_cs, tag)
		{
		}
		mrpc_guild_alert_surrender_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_surrender_cs)
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

	class mrpc_guild_alert_surrender_sc : public RpcPacket 	// // 항복 알림 패킷
	{
	public:
		std::vector<int64_t> list_cuid{};
	public:
		int64_t loser_guid{};	// // 항복한 문파 id
	public:
		std::string loser_guild_name{};	// // 항복한 문파명
	public:
		int32_t current_reject_count{};	// // 현재 거절 횟수
	public:
		int32_t negotiation_gold{};	// // 협상 시도 금액
	public:
		int64_t negotiation_expire_time{};	// // 자동 항복거부 처리 시간 (초)

	public:
		mrpc_guild_alert_surrender_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_surrender_sc, tag)
		{
		}
		mrpc_guild_alert_surrender_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_surrender_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &loser_guid);
			protocol::SerializeType(pBuffer, &loser_guild_name);
			protocol::SerializeType(pBuffer, &current_reject_count);
			protocol::SerializeType(pBuffer, &negotiation_gold);
			protocol::SerializeType(pBuffer, &negotiation_expire_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
