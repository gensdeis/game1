﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_storage_share_extend_cs : public RpcPacket 	// 문파 공유 창고 확장
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t extend_slot_count{};

	public:
		mrpc_guild_storage_share_extend_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_share_extend_cs, tag)
		{
		}
		mrpc_guild_storage_share_extend_cs() : RpcPacket(mpe_rpc_cmd::guild_storage_share_extend_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &extend_slot_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_storage_share_extend_sc : public RpcPacket 	// 문파 공유 창고 확장
	{
	public:
		int64_t cuid{};
	public:
		int32_t total_slot_count{};
	public:
		int32_t update_guild_gold{};
	public:
		int32_t total_guild_gold{};

	public:
		mrpc_guild_storage_share_extend_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_share_extend_sc, tag)
		{
		}
		mrpc_guild_storage_share_extend_sc() : RpcPacket(mpe_rpc_cmd::guild_storage_share_extend_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &total_slot_count);
			protocol::SerializeType(pBuffer, &update_guild_gold);
			protocol::SerializeType(pBuffer, &total_guild_gold);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
