﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_server_world_info_get_cs : public RpcPacket 
	{

	public:
		mrpc_gm_server_world_info_get_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_server_world_info_get_cs, tag)
		{
		}
		mrpc_gm_server_world_info_get_cs() : RpcPacket(mpe_rpc_cmd::gm_server_world_info_get_cs)
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

	class mrpc_gm_server_world_info_get_sc : public RpcPacket 
	{

	public:
		mrpc_gm_server_world_info_get_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_server_world_info_get_sc, tag)
		{
		}
		mrpc_gm_server_world_info_get_sc() : RpcPacket(mpe_rpc_cmd::gm_server_world_info_get_sc)
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
