#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_vehicle_equip_cs : public BasePacket 
	{
	public:
		int32_t vehicle_tid{};

	public:
		mp_vehicle_equip_cs() : BasePacket(mpe_cmd::vehicle_equip_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &vehicle_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_vehicle_equip_sc : public BasePacket 
	{
	public:
		int32_t vehicle_tid{};	// 0 일 경우 장착 실패

	public:
		mp_vehicle_equip_sc() : BasePacket(mpe_cmd::vehicle_equip_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &vehicle_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
