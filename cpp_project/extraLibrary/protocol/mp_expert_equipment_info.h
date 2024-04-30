#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_expert_equipment_info.h"

namespace mir3d
{
	class mp_expert_equipment_info_cs : public BasePacket 
	{

	public:
		mp_expert_equipment_info_cs() : BasePacket(mpe_cmd::expert_equipment_info_cs)
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

	class mp_expert_equipment_info_sc : public BasePacket 
	{
	public:
		std::vector<mps_expert_equipment_info> expert_equipment_list{};	// "보유한 전직 장비 목록"

	public:
		mp_expert_equipment_info_sc() : BasePacket(mpe_cmd::expert_equipment_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &expert_equipment_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
