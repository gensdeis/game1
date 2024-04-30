#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_character_level_up_cs : public BasePacket 
	{

	public:
		mp_zone_character_level_up_cs() : BasePacket(mpe_cmd::zone_character_level_up_cs)
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

	class mp_zone_character_level_up_sc : public BasePacket 
	{
	public:
		int64_t target_uid{};
	public:
		int32_t mhp{};	// // max hp

	public:
		mp_zone_character_level_up_sc() : BasePacket(mpe_cmd::zone_character_level_up_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_uid);
			protocol::SerializeType(pBuffer, &mhp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
