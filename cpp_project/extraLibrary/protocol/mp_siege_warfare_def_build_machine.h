#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_siege_machine.h"

namespace mir3d
{
	class mp_siege_warfare_def_build_machine_cs : public BasePacket 	// 수성병기 설치
	{
	public:
		int64_t nuid{};
	public:
		mpe_siege_castle_type castle_type{};	// 성 type
	public:
		std::vector<mps_siege_machine> machine_info{};	// 공성무기

	public:
		mp_siege_warfare_def_build_machine_cs() : BasePacket(mpe_cmd::siege_warfare_def_build_machine_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &machine_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_siege_warfare_def_build_machine_sc : public BasePacket 	// 수성병기 설치
	{

	public:
		mp_siege_warfare_def_build_machine_sc() : BasePacket(mpe_cmd::siege_warfare_def_build_machine_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
