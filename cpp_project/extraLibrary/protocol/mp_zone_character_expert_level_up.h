#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_character_expert_level_up_cs : public BasePacket 
	{

	public:
		mp_zone_character_expert_level_up_cs() : BasePacket(mpe_cmd::zone_character_expert_level_up_cs)
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

	class mp_zone_character_expert_level_up_sc : public BasePacket 
	{
	public:
		int64_t target_uid{};
	public:
		bool is_grade_up{};	// " true : 등급(등선,전직), false : 전직경험치획득레벨업"

	public:
		mp_zone_character_expert_level_up_sc() : BasePacket(mpe_cmd::zone_character_expert_level_up_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_uid);
			protocol::SerializeType(pBuffer, &is_grade_up);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
