#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_vehicle.h"

namespace mir3d
{
	class mp_gm_get_vehicle_cs : public BasePacket 
	{
	public:
		int32_t v_id{};	// 탈것id / 전체획득 0

	public:
		mp_gm_get_vehicle_cs() : BasePacket(mpe_cmd::gm_get_vehicle_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &v_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_get_vehicle_sc : public BasePacket 
	{
	public:
		std::vector<mps_vehicle> list{};

	public:
		mp_gm_get_vehicle_sc() : BasePacket(mpe_cmd::gm_get_vehicle_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
