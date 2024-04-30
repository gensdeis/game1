﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gm_seal_device_reset_cs : public BasePacket 
	{
	public:
		int64_t ouid{};	// //봉인장치 uid

	public:
		mp_gm_seal_device_reset_cs() : BasePacket(mpe_cmd::gm_seal_device_reset_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ouid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_seal_device_reset_sc : public BasePacket 
	{

	public:
		mp_gm_seal_device_reset_sc() : BasePacket(mpe_cmd::gm_seal_device_reset_sc)
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
