#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_alert_member_contribution_update_cs : public BasePacket 
	{

	public:
		mp_guild_alert_member_contribution_update_cs() : BasePacket(mpe_cmd::guild_alert_member_contribution_update_cs)
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

	class mp_guild_alert_member_contribution_update_sc : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t contribution_weekly_point{};
	public:
		int32_t contribution_accumulated_point{};

	public:
		mp_guild_alert_member_contribution_update_sc() : BasePacket(mpe_cmd::guild_alert_member_contribution_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &contribution_weekly_point);
			protocol::SerializeType(pBuffer, &contribution_accumulated_point);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
