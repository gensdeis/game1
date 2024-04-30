#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_log.h"

namespace mir3d
{
	class mp_gate_castle_town_log_cs : public BasePacket 
	{
	public:
		int64_t guid{};

	public:
		mp_gate_castle_town_log_cs() : BasePacket(mpe_cmd::gate_castle_town_log_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_castle_town_log_sc : public BasePacket 
	{
	public:
		std::vector<mps_castle_town_log> castle_town_log_list{};

	public:
		mp_gate_castle_town_log_sc() : BasePacket(mpe_cmd::gate_castle_town_log_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &castle_town_log_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
