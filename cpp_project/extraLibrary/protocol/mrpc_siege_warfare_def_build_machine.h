#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_siege_machine.h"
#include "struct/mps_siege_machine.h"

namespace mir3d
{
	class mrpc_siege_warfare_def_build_machine_cs : public RpcPacket 	// 수성병기 설치
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		mpe_siege_castle_type castle_type{};	// 성 type
	public:
		std::vector<mps_siege_machine> machine_info{};	// 공성무기

	public:
		mrpc_siege_warfare_def_build_machine_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_def_build_machine_cs, tag)
		{
		}
		mrpc_siege_warfare_def_build_machine_cs() : RpcPacket(mpe_rpc_cmd::siege_warfare_def_build_machine_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &machine_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_siege_warfare_def_build_machine_sc : public RpcPacket 	// 수성병기 설치
	{
	public:
		int64_t key{};
	public:
		mpe_siege_castle_type castle_type{};	// 성 type
	public:
		std::vector<mps_siege_machine> machine_info{};	// 공성무기

	public:
		mrpc_siege_warfare_def_build_machine_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_def_build_machine_sc, tag)
		{
		}
		mrpc_siege_warfare_def_build_machine_sc() : RpcPacket(mpe_rpc_cmd::siege_warfare_def_build_machine_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &machine_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
