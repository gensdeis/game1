﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_api_user_kick_cs : public RpcPacket 
	{
	public:
		std::vector<int64_t> list_kick_user{};
	public:
		int64_t key{};	// gm server key

	public:
		mrpc_gm_api_user_kick_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_api_user_kick_cs, tag)
		{
		}
		mrpc_gm_api_user_kick_cs() : RpcPacket(mpe_rpc_cmd::gm_api_user_kick_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_kick_user);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_api_user_kick_sc : public RpcPacket 
	{
	public:
		int64_t key{};	// gm server key

	public:
		mrpc_gm_api_user_kick_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_api_user_kick_sc, tag)
		{
		}
		mrpc_gm_api_user_kick_sc() : RpcPacket(mpe_rpc_cmd::gm_api_user_kick_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}