#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_character_power_cs : public BasePacket 
	{
	public:
		int32_t power{};
	public:
		int32_t power2{};
	public:
		bool power_event{};

	public:
		mp_character_power_cs() : BasePacket(mpe_cmd::character_power_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &power);
			protocol::SerializeType(pBuffer, &power2);
			protocol::SerializeType(pBuffer, &power_event);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_character_power_sc : public BasePacket 
	{
	public:
		int32_t power{};
	public:
		bool power_event{};

	public:
		mp_character_power_sc() : BasePacket(mpe_cmd::character_power_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &power);
			protocol::SerializeType(pBuffer, &power_event);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
