#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_siege_machine.h"

namespace mir3d
{
	class mrpc_gate_siege_warfare_atk_machine_info_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		mpe_siege_castle_type castle_type{};	// 성타입
	public:
		int64_t guid{};	// 길드아이디

	public:
		mrpc_gate_siege_warfare_atk_machine_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_siege_warfare_atk_machine_info_cs, tag)
		{
		}
		mrpc_gate_siege_warfare_atk_machine_info_cs() : RpcPacket(mpe_rpc_cmd::gate_siege_warfare_atk_machine_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_siege_warfare_atk_machine_info_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_siege_machine> machine_info{};	// 공성무기

	public:
		mrpc_gate_siege_warfare_atk_machine_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_siege_warfare_atk_machine_info_sc, tag)
		{
		}
		mrpc_gate_siege_warfare_atk_machine_info_sc() : RpcPacket(mpe_rpc_cmd::gate_siege_warfare_atk_machine_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &machine_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
