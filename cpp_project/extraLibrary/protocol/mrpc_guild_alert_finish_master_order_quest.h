#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_alert_finish_master_order_quest_cs : public RpcPacket 
	{

	public:
		mrpc_guild_alert_finish_master_order_quest_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_finish_master_order_quest_cs, tag)
		{
		}
		mrpc_guild_alert_finish_master_order_quest_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_finish_master_order_quest_cs)
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

	class mrpc_guild_alert_finish_master_order_quest_sc : public RpcPacket 
	{
	public:
		std::vector<int64_t> list_cuid{};
	public:
		int32_t current_finish_member_count{};

	public:
		mrpc_guild_alert_finish_master_order_quest_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_finish_master_order_quest_sc, tag)
		{
		}
		mrpc_guild_alert_finish_master_order_quest_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_finish_master_order_quest_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &current_finish_member_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
