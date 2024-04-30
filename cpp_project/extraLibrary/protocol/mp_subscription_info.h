﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_subscription_info.h"

namespace mir3d
{
	class mp_subscription_info_cs : public BasePacket 
	{

	public:
		mp_subscription_info_cs() : BasePacket(mpe_cmd::subscription_info_cs)
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

	class mp_subscription_info_sc : public BasePacket 
	{
	public:
		std::vector<mps_subscription_info> subscription_info_list{};

	public:
		mp_subscription_info_sc() : BasePacket(mpe_cmd::subscription_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &subscription_info_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}