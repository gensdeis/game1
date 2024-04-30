#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_token_balance.h"

namespace mir3d
{
	class mrpc_gate_get_all_balance_swap_token_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		std::string user_address{};

	public:
		mrpc_gate_get_all_balance_swap_token_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_get_all_balance_swap_token_cs, tag)
		{
		}
		mrpc_gate_get_all_balance_swap_token_cs() : RpcPacket(mpe_rpc_cmd::gate_get_all_balance_swap_token_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &user_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_get_all_balance_swap_token_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_token_balance> token_balance{};
	public:
		int32_t result{};

	public:
		mrpc_gate_get_all_balance_swap_token_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_get_all_balance_swap_token_sc, tag)
		{
		}
		mrpc_gate_get_all_balance_swap_token_sc() : RpcPacket(mpe_rpc_cmd::gate_get_all_balance_swap_token_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &token_balance);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
