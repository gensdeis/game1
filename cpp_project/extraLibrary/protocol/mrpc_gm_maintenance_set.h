﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_maintenance_set_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		bool flag{};

	public:
		mrpc_gm_maintenance_set_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_maintenance_set_cs, tag)
		{
		}
		mrpc_gm_maintenance_set_cs() : RpcPacket(mpe_rpc_cmd::gm_maintenance_set_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_maintenance_set_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		bool flag{};

	public:
		mrpc_gm_maintenance_set_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_maintenance_set_sc, tag)
		{
		}
		mrpc_gm_maintenance_set_sc() : RpcPacket(mpe_rpc_cmd::gm_maintenance_set_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
