#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_secretvalley_owner_info.h"

namespace mir3d
{
	class mp_gate_secretvalley_owner_info_cs : public BasePacket 
	{

	public:
		mp_gate_secretvalley_owner_info_cs() : BasePacket(mpe_cmd::gate_secretvalley_owner_info_cs)
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

	class mp_gate_secretvalley_owner_info_sc : public BasePacket 
	{
	public:
		std::vector<mps_secretvalley_owner_info> secretvalley_infos{};

	public:
		mp_gate_secretvalley_owner_info_sc() : BasePacket(mpe_cmd::gate_secretvalley_owner_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &secretvalley_infos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
