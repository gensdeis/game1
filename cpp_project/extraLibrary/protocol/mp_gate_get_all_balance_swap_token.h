#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_token_balance.h"

namespace mir3d
{
	class mp_gate_get_all_balance_swap_token_cs : public BasePacket 
	{
	public:
		int64_t auid{};
	public:
		std::string user_address{};

	public:
		mp_gate_get_all_balance_swap_token_cs() : BasePacket(mpe_cmd::gate_get_all_balance_swap_token_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &user_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_get_all_balance_swap_token_sc : public BasePacket 
	{
	public:
		std::vector<mps_token_balance> token_balance{};
	public:
		int32_t result{};

	public:
		mp_gate_get_all_balance_swap_token_sc() : BasePacket(mpe_cmd::gate_get_all_balance_swap_token_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &token_balance);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
