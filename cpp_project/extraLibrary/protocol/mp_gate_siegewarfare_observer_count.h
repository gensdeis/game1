#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_siegewarfare_observer_count_cs : public BasePacket 
	{
	public:
		mpe_siege_castle_type castle_type{};

	public:
		mp_gate_siegewarfare_observer_count_cs() : BasePacket(mpe_cmd::gate_siegewarfare_observer_count_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &castle_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_siegewarfare_observer_count_sc : public BasePacket 
	{
	public:
		uint8_t observer_count{};

	public:
		mp_gate_siegewarfare_observer_count_sc() : BasePacket(mpe_cmd::gate_siegewarfare_observer_count_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &observer_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
