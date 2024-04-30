﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_revive.h"

namespace mir3d
{
	class mrpc_get_revive_list_cs : public RpcPacket 
	{

	public:
		mrpc_get_revive_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::get_revive_list_cs, tag)
		{
		}
		mrpc_get_revive_list_cs() : RpcPacket(mpe_rpc_cmd::get_revive_list_cs)
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

	class mrpc_get_revive_list_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_revive> list{};

	public:
		mrpc_get_revive_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::get_revive_list_sc, tag)
		{
		}
		mrpc_get_revive_list_sc() : RpcPacket(mpe_rpc_cmd::get_revive_list_sc)
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