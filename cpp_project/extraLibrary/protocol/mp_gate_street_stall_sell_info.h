#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_street_stall_fees.h"

namespace mir3d
{
	class mp_gate_street_stall_sell_info_cs : public BasePacket 
	{
	public:
		int64_t suid{};	// 상점 uid

	public:
		mp_gate_street_stall_sell_info_cs() : BasePacket(mpe_cmd::gate_street_stall_sell_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &suid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_street_stall_sell_info_sc : public BasePacket 
	{
	public:
		std::vector<mps_street_stall_fees> total_fees{};
	public:
		int32_t use_count{};

	public:
		mp_gate_street_stall_sell_info_sc() : BasePacket(mpe_cmd::gate_street_stall_sell_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &total_fees);
			protocol::SerializeType(pBuffer, &use_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
