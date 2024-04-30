﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_community_character_levelup_cs : public RpcPacket 
	{

	public:
		mrpc_community_character_levelup_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_character_levelup_cs, tag)
		{
		}
		mrpc_community_character_levelup_cs() : RpcPacket(mpe_rpc_cmd::community_character_levelup_cs)
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

	class mrpc_community_character_levelup_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t level{};
	public:
		int32_t expert_level{};

	public:
		mrpc_community_character_levelup_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_character_levelup_sc, tag)
		{
		}
		mrpc_community_character_levelup_sc() : RpcPacket(mpe_rpc_cmd::community_character_levelup_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
