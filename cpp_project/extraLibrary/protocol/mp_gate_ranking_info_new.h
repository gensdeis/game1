#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_ranking_info_new.h"

namespace mir3d
{
	class mp_gate_ranking_info_new_cs : public BasePacket 
	{
	public:
		mpe_ranking_type ranking_type{};

	public:
		mp_gate_ranking_info_new_cs() : BasePacket(mpe_cmd::gate_ranking_info_new_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &ranking_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_ranking_info_new_sc : public BasePacket 
	{
	public:
		std::vector<mps_ranking_info_new> ranking_list{};

	public:
		mp_gate_ranking_info_new_sc() : BasePacket(mpe_cmd::gate_ranking_info_new_sc)
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
