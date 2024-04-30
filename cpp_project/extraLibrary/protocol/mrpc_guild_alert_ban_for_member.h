#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_alert_ban_for_member_cs : public RpcPacket 	// // 문파 추방 알림 패킷 (남은 문파원)
	{

	public:
		mrpc_guild_alert_ban_for_member_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_ban_for_member_cs, tag)
		{
		}
		mrpc_guild_alert_ban_for_member_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_ban_for_member_cs)
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

	class mrpc_guild_alert_ban_for_member_sc : public RpcPacket 	// // 문파 추방 알림 패킷 (남은 문파원)
	{
	public:
		std::vector<int64_t> list_cuid{};	// // 패킷받아야할 대상
	public:
		int64_t ban_member_cuid{};	// // 추방된 유저ID
	public:
		std::string ban_member_name{};	// // 추방된 유저명

	public:
		mrpc_guild_alert_ban_for_member_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_ban_for_member_sc, tag)
		{
		}
		mrpc_guild_alert_ban_for_member_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_ban_for_member_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &ban_member_cuid);
			protocol::SerializeType(pBuffer, &ban_member_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
