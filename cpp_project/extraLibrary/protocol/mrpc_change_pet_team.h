﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_change_pet_team_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		mpe_pet_team team{};

	public:
		mrpc_change_pet_team_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::change_pet_team_cs, tag)
		{
		}
		mrpc_change_pet_team_cs() : RpcPacket(mpe_rpc_cmd::change_pet_team_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &team);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_change_pet_team_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_change_pet_team_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::change_pet_team_sc, tag)
		{
		}
		mrpc_change_pet_team_sc() : RpcPacket(mpe_rpc_cmd::change_pet_team_sc)
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