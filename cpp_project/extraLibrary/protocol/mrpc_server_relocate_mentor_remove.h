﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_server_relocate_mentor_remove_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};	// "캐릭터UID"

	public:
		mrpc_server_relocate_mentor_remove_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_relocate_mentor_remove_cs, tag)
		{
		}
		mrpc_server_relocate_mentor_remove_cs() : RpcPacket(mpe_rpc_cmd::server_relocate_mentor_remove_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_server_relocate_mentor_remove_sc : public RpcPacket 
	{

	public:
		mrpc_server_relocate_mentor_remove_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_relocate_mentor_remove_sc, tag)
		{
		}
		mrpc_server_relocate_mentor_remove_sc() : RpcPacket(mpe_rpc_cmd::server_relocate_mentor_remove_sc)
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