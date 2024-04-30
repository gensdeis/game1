#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_alert_change_notice_cs : public RpcPacket 	// 문파 공지 변경 알림
	{

	public:
		mrpc_guild_alert_change_notice_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_change_notice_cs, tag)
		{
		}
		mrpc_guild_alert_change_notice_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_change_notice_cs)
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

	class mrpc_guild_alert_change_notice_sc : public RpcPacket 	// 문파 공지 변경 알림
	{
	public:
		std::vector<int64_t> list_cuid{};
	public:
		std::string notice{};
	public:
		int64_t notice_update_time{};

	public:
		mrpc_guild_alert_change_notice_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_change_notice_sc, tag)
		{
		}
		mrpc_guild_alert_change_notice_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_change_notice_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &notice);
			protocol::SerializeType(pBuffer, &notice_update_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
