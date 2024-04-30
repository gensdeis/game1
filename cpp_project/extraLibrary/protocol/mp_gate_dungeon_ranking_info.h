#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_ranking_info_new.h"

namespace mir3d
{
	class mp_gate_dungeon_ranking_info_cs : public BasePacket 
	{
	public:
		int32_t dungeon_id{};

	public:
		mp_gate_dungeon_ranking_info_cs() : BasePacket(mpe_cmd::gate_dungeon_ranking_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &dungeon_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_dungeon_ranking_info_sc : public BasePacket 
	{
	public:
		std::vector<mps_ranking_info_new> ranking_list{};

	public:
		mp_gate_dungeon_ranking_info_sc() : BasePacket(mpe_cmd::gate_dungeon_ranking_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ranking_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
