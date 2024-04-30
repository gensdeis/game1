﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_gold_alert_cs : public RpcPacket 
	{

	public:
		mrpc_guild_gold_alert_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_gold_alert_cs, tag)
		{
		}
		mrpc_guild_gold_alert_cs() : RpcPacket(mpe_rpc_cmd::guild_gold_alert_cs)
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

	class mrpc_guild_gold_alert_sc : public RpcPacket 
	{
	public:
		std::vector<int64_t> list_cuid{};
	public:
		int32_t guild_gold{};

	public:
		mrpc_guild_gold_alert_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_gold_alert_sc, tag)
		{
		}
		mrpc_guild_gold_alert_sc() : RpcPacket(mpe_rpc_cmd::guild_gold_alert_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &guild_gold);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}