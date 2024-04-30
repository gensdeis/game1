﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_tool_remove_guild_storage_treasure_cs : public RpcPacket 
	{
	public:
		int64_t guid{};
	public:
		int64_t auction_uid{};

	public:
		mrpc_gm_tool_remove_guild_storage_treasure_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_tool_remove_guild_storage_treasure_cs, tag)
		{
		}
		mrpc_gm_tool_remove_guild_storage_treasure_cs() : RpcPacket(mpe_rpc_cmd::gm_tool_remove_guild_storage_treasure_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &auction_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_tool_remove_guild_storage_treasure_sc : public RpcPacket 
	{

	public:
		mrpc_gm_tool_remove_guild_storage_treasure_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_tool_remove_guild_storage_treasure_sc, tag)
		{
		}
		mrpc_gm_tool_remove_guild_storage_treasure_sc() : RpcPacket(mpe_rpc_cmd::gm_tool_remove_guild_storage_treasure_sc)
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