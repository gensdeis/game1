#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_member_pk_death_alert_cs : public RpcPacket 	// "길드원이 pk 사망함 알림."
	{
	public:
		int64_t guid{};	// "길드 uid"
	public:
		int64_t killer_guid{};	// "죽인 유저의 길드 uid"

	public:
		mrpc_guild_member_pk_death_alert_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_member_pk_death_alert_cs, tag)
		{
		}
		mrpc_guild_member_pk_death_alert_cs() : RpcPacket(mpe_rpc_cmd::guild_member_pk_death_alert_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &killer_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_member_pk_death_alert_sc : public RpcPacket 	// "길드원이 pk 사망함 알림."
	{
	public:
		std::vector<int64_t> list_cuid{};	// "패킷받아야할 대상"

	public:
		mrpc_guild_member_pk_death_alert_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_member_pk_death_alert_sc, tag)
		{
		}
		mrpc_guild_member_pk_death_alert_sc() : RpcPacket(mpe_rpc_cmd::guild_member_pk_death_alert_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
