#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_alert_change_mark_cs : public RpcPacket 
	{

	public:
		mrpc_guild_alert_change_mark_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_change_mark_cs, tag)
		{
		}
		mrpc_guild_alert_change_mark_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_change_mark_cs)
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

	class mrpc_guild_alert_change_mark_sc : public RpcPacket 
	{
	public:
		std::vector<int64_t> list_cuid{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t guild_gold{};

	public:
		mrpc_guild_alert_change_mark_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_change_mark_sc, tag)
		{
		}
		mrpc_guild_alert_change_mark_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_change_mark_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &guild_gold);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
