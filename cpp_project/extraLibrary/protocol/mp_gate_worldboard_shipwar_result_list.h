#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_shipwar_character_season_info.h"

namespace mir3d
{
	class mp_gate_worldboard_shipwar_result_list_cs : public BasePacket 
	{
	public:
		int64_t guid{};

	public:
		mp_gate_worldboard_shipwar_result_list_cs() : BasePacket(mpe_cmd::gate_worldboard_shipwar_result_list_cs)
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

	class mp_gate_worldboard_shipwar_result_list_sc : public BasePacket 
	{
	public:
		std::vector<mps_shipwar_character_season_info> season_info{};

	public:
		mp_gate_worldboard_shipwar_result_list_sc() : BasePacket(mpe_cmd::gate_worldboard_shipwar_result_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &season_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
