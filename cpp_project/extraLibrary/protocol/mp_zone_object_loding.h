﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_object_info.h"

namespace mir3d
{
	class mp_zone_object_loding_cs : public BasePacket 
	{

	public:
		mp_zone_object_loding_cs() : BasePacket(mpe_cmd::zone_object_loding_cs)
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

	class mp_zone_object_loding_sc : public BasePacket 
	{
	public:
		std::vector<mps_zone_object_info> info{};	// 맵의 오브젝트 정보(리스트)

	public:
		mp_zone_object_loding_sc() : BasePacket(mpe_cmd::zone_object_loding_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}