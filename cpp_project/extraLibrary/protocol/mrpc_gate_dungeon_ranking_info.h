﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_ranking_info_new.h"

namespace mir3d
{
	class mrpc_gate_dungeon_ranking_info_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t dungeon_id{};	// 던전 id

	public:
		mrpc_gate_dungeon_ranking_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_dungeon_ranking_info_cs, tag)
		{
		}
		mrpc_gate_dungeon_ranking_info_cs() : RpcPacket(mpe_rpc_cmd::gate_dungeon_ranking_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &dungeon_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_dungeon_ranking_info_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_ranking_info_new> ranking_list{};

	public:
		mrpc_gate_dungeon_ranking_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_dungeon_ranking_info_sc, tag)
		{
		}
		mrpc_gate_dungeon_ranking_info_sc() : RpcPacket(mpe_rpc_cmd::gate_dungeon_ranking_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &ranking_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
