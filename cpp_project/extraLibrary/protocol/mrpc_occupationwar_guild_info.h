﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_occupationwar_guild_info.h"

namespace mir3d
{
	class mrpc_occupationwar_guild_info_cs : public RpcPacket 	// 비곡점령전 문파정보
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};

	public:
		mrpc_occupationwar_guild_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::occupationwar_guild_info_cs, tag)
		{
		}
		mrpc_occupationwar_guild_info_cs() : RpcPacket(mpe_rpc_cmd::occupationwar_guild_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_occupationwar_guild_info_sc : public RpcPacket 	// 비곡점령전 문파정보
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_occupationwar_guild_info> list{};

	public:
		mrpc_occupationwar_guild_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::occupationwar_guild_info_sc, tag)
		{
		}
		mrpc_occupationwar_guild_info_sc() : RpcPacket(mpe_rpc_cmd::occupationwar_guild_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
