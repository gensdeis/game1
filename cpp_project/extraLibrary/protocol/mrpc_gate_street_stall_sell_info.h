﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_street_stall_fees.h"

namespace mir3d
{
	class mrpc_gate_street_stall_sell_info_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t suid{};	// 상점 uid

	public:
		mrpc_gate_street_stall_sell_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_street_stall_sell_info_cs, tag)
		{
		}
		mrpc_gate_street_stall_sell_info_cs() : RpcPacket(mpe_rpc_cmd::gate_street_stall_sell_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &suid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_street_stall_sell_info_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_street_stall_fees> total_fees{};
	public:
		int32_t use_count{};

	public:
		mrpc_gate_street_stall_sell_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_street_stall_sell_info_sc, tag)
		{
		}
		mrpc_gate_street_stall_sell_info_sc() : RpcPacket(mpe_rpc_cmd::gate_street_stall_sell_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &total_fees);
			protocol::SerializeType(pBuffer, &use_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}