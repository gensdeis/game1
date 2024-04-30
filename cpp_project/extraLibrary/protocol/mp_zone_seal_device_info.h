﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_object_info.h"

namespace mir3d
{
	class mp_zone_seal_device_info_cs : public BasePacket 
	{

	public:
		mp_zone_seal_device_info_cs() : BasePacket(mpe_cmd::zone_seal_device_info_cs)
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

	class mp_zone_seal_device_info_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_zone_object_info info;	// // 맵의 봉인장치 정보(리스트)
		mps_zone_object_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_zone_object_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_zone_object_info* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_zone_object_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_zone_seal_device_info_sc() : BasePacket(mpe_cmd::zone_seal_device_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}