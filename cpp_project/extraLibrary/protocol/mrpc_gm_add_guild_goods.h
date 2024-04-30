﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_add_guild_goods_cs : public RpcPacket 
	{
	public:
		int32_t item_id{};
	public:
		int32_t add_count{};
	public:
		int64_t guid{};
	public:
		int64_t key{};

	public:
		mrpc_gm_add_guild_goods_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_add_guild_goods_cs, tag)
		{
		}
		mrpc_gm_add_guild_goods_cs() : RpcPacket(mpe_rpc_cmd::gm_add_guild_goods_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &item_id);
			protocol::SerializeType(pBuffer, &add_count);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_add_guild_goods_sc : public RpcPacket 
	{

	public:
		mrpc_gm_add_guild_goods_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_add_guild_goods_sc, tag)
		{
		}
		mrpc_gm_add_guild_goods_sc() : RpcPacket(mpe_rpc_cmd::gm_add_guild_goods_sc)
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