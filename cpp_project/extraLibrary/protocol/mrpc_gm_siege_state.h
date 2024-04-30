﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_siege_state_cs : public RpcPacket 
	{
	public:
		mpe_siege_castle_type castle{};
	public:
		mpe_siege_warfare_state state{};
	public:
		int64_t guid{};
	public:
		int64_t cuid{};
	public:
		int64_t key{};

	public:
		mrpc_gm_siege_state_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_siege_state_cs, tag)
		{
		}
		mrpc_gm_siege_state_cs() : RpcPacket(mpe_rpc_cmd::gm_siege_state_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &castle);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_siege_state_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		mpe_siege_castle_type castle{};
	public:
		mpe_siege_warfare_state state{};

	public:
		mrpc_gm_siege_state_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_siege_state_sc, tag)
		{
		}
		mrpc_gm_siege_state_sc() : RpcPacket(mpe_rpc_cmd::gm_siege_state_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &castle);
			protocol::SerializeEnum(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
