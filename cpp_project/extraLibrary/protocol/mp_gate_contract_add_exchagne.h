#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_contract_add_exchagne_cs : public BasePacket 	// 가능 수량 조회
	{
	public:
		int64_t auid{};
	public:
		std::string user_address{};

	public:
		mp_gate_contract_add_exchagne_cs() : BasePacket(mpe_cmd::gate_contract_add_exchagne_cs)
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

	class mp_gate_contract_add_exchagne_sc : public BasePacket 	// 가능 수량 조회
	{
	public:
		std::string drone_amount{};	// 드론 현재 발행량
	public:
		std::string user_amount{};	// 유저 현재 발행량

	public:
		mp_gate_contract_add_exchagne_sc() : BasePacket(mpe_cmd::gate_contract_add_exchagne_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &drone_amount);
			protocol::SerializeType(pBuffer, &user_amount);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
