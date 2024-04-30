#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_wanted_murder_info.h"

namespace mir3d
{
	class mp_gate_wanted_murder_list_cs : public BasePacket 
	{
	public:
		int64_t cuid{};

	public:
		mp_gate_wanted_murder_list_cs() : BasePacket(mpe_cmd::gate_wanted_murder_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_wanted_murder_list_sc : public BasePacket 
	{
	public:
		std::vector<mps_wanted_murder_info> info{};

	public:
		mp_gate_wanted_murder_list_sc() : BasePacket(mpe_cmd::gate_wanted_murder_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
