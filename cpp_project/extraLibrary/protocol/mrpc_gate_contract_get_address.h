﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_contract_get_address_cs : public RpcPacket 	// 컨트랙트 주소 조회
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		mpe_token_type token_type{};

	public:
		mrpc_gate_contract_get_address_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_contract_get_address_cs, tag)
		{
		}
		mrpc_gate_contract_get_address_cs() : RpcPacket(mpe_rpc_cmd::gate_contract_get_address_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeEnum(pBuffer, &token_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_contract_get_address_sc : public RpcPacket 	// 컨트랙트 주소 조회
	{
	public:
		int64_t key{};
	public:
		std::string address{};	// 주소

	public:
		mrpc_gate_contract_get_address_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_contract_get_address_sc, tag)
		{
		}
		mrpc_gate_contract_get_address_sc() : RpcPacket(mpe_rpc_cmd::gate_contract_get_address_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}