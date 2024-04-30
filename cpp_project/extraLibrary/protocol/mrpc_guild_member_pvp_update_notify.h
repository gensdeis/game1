﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_member_pvp_update_notify_cs : public RpcPacket 
	{
	public:
		int64_t guid{};

	public:
		mrpc_guild_member_pvp_update_notify_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_member_pvp_update_notify_cs, tag)
		{
		}
		mrpc_guild_member_pvp_update_notify_cs() : RpcPacket(mpe_rpc_cmd::guild_member_pvp_update_notify_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_member_pvp_update_notify_sc : public RpcPacket 
	{

	public:
		mrpc_guild_member_pvp_update_notify_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_member_pvp_update_notify_sc, tag)
		{
		}
		mrpc_guild_member_pvp_update_notify_sc() : RpcPacket(mpe_rpc_cmd::guild_member_pvp_update_notify_sc)
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

}