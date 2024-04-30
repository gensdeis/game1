#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_siege_machine.h"

namespace mir3d
{
	class mp_gate_siege_warfare_atk_machine_info_cs : public BasePacket 
	{
	public:
		mpe_siege_castle_type castle_type{};	// 성타입
	public:
		int64_t guid{};	// 길드아이디

	public:
		mp_gate_siege_warfare_atk_machine_info_cs() : BasePacket(mpe_cmd::gate_siege_warfare_atk_machine_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_siege_warfare_atk_machine_info_sc : public BasePacket 
	{
	public:
		std::vector<mps_siege_machine> machine_info{};	// 공성무기

	public:
		mp_gate_siege_warfare_atk_machine_info_sc() : BasePacket(mpe_cmd::gate_siege_warfare_atk_machine_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &machine_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
