﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_global_exchange_register_complete_cs : public RpcPacket 	// 거래소 아이템 등록 완료
	{
	public:
		int64_t key{};
	public:
		int64_t ruid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mrpc_global_exchange_register_complete_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_exchange_register_complete_cs, tag)
		{
		}
		mrpc_global_exchange_register_complete_cs() : RpcPacket(mpe_rpc_cmd::global_exchange_register_complete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &ruid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_global_exchange_register_complete_sc : public RpcPacket 	// 거래소 아이템 등록 완료
	{
	public:
		int64_t key{};
	public:
		int64_t ruid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mrpc_global_exchange_register_complete_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_exchange_register_complete_sc, tag)
		{
		}
		mrpc_global_exchange_register_complete_sc() : RpcPacket(mpe_rpc_cmd::global_exchange_register_complete_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &ruid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
