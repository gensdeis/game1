﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_lobby_gamelogin_await_cancel_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		std::string access_token{};

	public:
		mrpc_gate_lobby_gamelogin_await_cancel_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_lobby_gamelogin_await_cancel_cs, tag)
		{
		}
		mrpc_gate_lobby_gamelogin_await_cancel_cs() : RpcPacket(mpe_rpc_cmd::gate_lobby_gamelogin_await_cancel_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_lobby_gamelogin_await_cancel_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gate_lobby_gamelogin_await_cancel_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_lobby_gamelogin_await_cancel_sc, tag)
		{
		}
		mrpc_gate_lobby_gamelogin_await_cancel_sc() : RpcPacket(mpe_rpc_cmd::gate_lobby_gamelogin_await_cancel_sc)
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
