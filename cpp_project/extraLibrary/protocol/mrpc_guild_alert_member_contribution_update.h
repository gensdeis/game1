#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_alert_member_contribution_update_cs : public RpcPacket 
	{

	public:
		mrpc_guild_alert_member_contribution_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_member_contribution_update_cs, tag)
		{
		}
		mrpc_guild_alert_member_contribution_update_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_member_contribution_update_cs)
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

	class mrpc_guild_alert_member_contribution_update_sc : public RpcPacket 
	{
	public:
		std::vector<int64_t> list_cuid{};
	public:
		int64_t cuid{};
	public:
		int32_t contribution_weekly_point{};
	public:
		int32_t contribution_accumulated_point{};

	public:
		mrpc_guild_alert_member_contribution_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_member_contribution_update_sc, tag)
		{
		}
		mrpc_guild_alert_member_contribution_update_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_member_contribution_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &contribution_weekly_point);
			protocol::SerializeType(pBuffer, &contribution_accumulated_point);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
