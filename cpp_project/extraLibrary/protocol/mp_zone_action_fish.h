#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_action_fish_cs : public BasePacket 
	{

	public:
		mp_zone_action_fish_cs() : BasePacket(mpe_cmd::zone_action_fish_cs)
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

	class mp_zone_action_fish_sc : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		mpe_character_action action{};
	public:
		mpe_result_fish result{};
	public:
		mpe_direction direction{};

	public:
		mp_zone_action_fish_sc() : BasePacket(mpe_cmd::zone_action_fish_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &action);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeEnum(pBuffer, &direction);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
