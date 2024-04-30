﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_seasonpass.h"

namespace mir3d
{
	class mrpc_seasonpass_change_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_seasonpass> list{};

	public:
		mrpc_seasonpass_change_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::seasonpass_change_cs, tag)
		{
		}
		mrpc_seasonpass_change_cs() : RpcPacket(mpe_rpc_cmd::seasonpass_change_cs)
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

	class mrpc_seasonpass_change_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_seasonpass_change_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::seasonpass_change_sc, tag)
		{
		}
		mrpc_seasonpass_change_sc() : RpcPacket(mpe_rpc_cmd::seasonpass_change_sc)
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