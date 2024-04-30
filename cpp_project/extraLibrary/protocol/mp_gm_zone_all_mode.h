﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gm_zone_all_mode_cs : public BasePacket 
	{
	public:
		bool all_mode{};	// "true/시작, false/종료"

	public:
		mp_gm_zone_all_mode_cs() : BasePacket(mpe_cmd::gm_zone_all_mode_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &all_mode);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_zone_all_mode_sc : public BasePacket 
	{

	public:
		mp_gm_zone_all_mode_sc() : BasePacket(mpe_cmd::gm_zone_all_mode_sc)
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

}
