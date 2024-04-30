#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_expert_equipment_ability_ready_cs : public BasePacket 
	{

	public:
		mp_expert_equipment_ability_ready_cs() : BasePacket(mpe_cmd::expert_equipment_ability_ready_cs)
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

	class mp_expert_equipment_ability_ready_sc : public BasePacket 
	{

	public:
		mp_expert_equipment_ability_ready_sc() : BasePacket(mpe_cmd::expert_equipment_ability_ready_sc)
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
