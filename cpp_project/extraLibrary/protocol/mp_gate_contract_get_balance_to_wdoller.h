#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_contract_get_balance_to_wdoller_cs : public BasePacket 	// wemixdoller 토큰 수량 조회
	{
	public:
		int64_t auid{};
	public:
		std::string user_address{};

	public:
		mp_gate_contract_get_balance_to_wdoller_cs() : BasePacket(mpe_cmd::gate_contract_get_balance_to_wdoller_cs)
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

	class mp_gate_contract_get_balance_to_wdoller_sc : public BasePacket 	// wemixdoller 토큰 수량 조회
	{
	public:
		std::string wdoller{};	// wdoller 수량

	public:
		mp_gate_contract_get_balance_to_wdoller_sc() : BasePacket(mpe_cmd::gate_contract_get_balance_to_wdoller_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &wdoller);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
