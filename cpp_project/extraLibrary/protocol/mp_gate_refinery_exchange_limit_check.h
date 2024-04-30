#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_refinery_exchange_limit_check_cs : public BasePacket 	// 제련소 교환횟수 조건체크
	{
	public:
		int64_t auid{};

	public:
		mp_gate_refinery_exchange_limit_check_cs() : BasePacket(mpe_cmd::gate_refinery_exchange_limit_check_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_refinery_exchange_limit_check_sc : public BasePacket 	// 제련소 교환횟수 조건체크
	{
	public:
		int32_t daily_exchange_limit{};	// 일일 교환제한 횟수

	public:
		mp_gate_refinery_exchange_limit_check_sc() : BasePacket(mpe_cmd::gate_refinery_exchange_limit_check_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &daily_exchange_limit);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
