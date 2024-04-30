#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_action_state_cs : public BasePacket 
	{

	public:
		mp_zone_action_state_cs() : BasePacket(mpe_cmd::zone_action_state_cs)
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

	class mp_zone_action_state_sc : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		mpe_character_action action{};
	public:
		int64_t target_uid{};

	public:
		mp_zone_action_state_sc() : BasePacket(mpe_cmd::zone_action_state_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &action);
			protocol::SerializeType(pBuffer, &target_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
