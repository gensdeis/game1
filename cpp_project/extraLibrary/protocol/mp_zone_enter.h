#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_object_info.h"

namespace mir3d
{
	class mp_zone_enter_cs : public BasePacket 	// 존 진입
	{

	public:
		mp_zone_enter_cs() : BasePacket(mpe_cmd::zone_enter_cs)
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

	class mp_zone_enter_sc : public BasePacket 	// 존 진입
	{
	public:
		std::vector<mps_zone_object_info> object_info{};
	public:
		int64_t send_time{};

	public:
		mp_zone_enter_sc() : BasePacket(mpe_cmd::zone_enter_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &object_info);
			protocol::SerializeType(pBuffer, &send_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
