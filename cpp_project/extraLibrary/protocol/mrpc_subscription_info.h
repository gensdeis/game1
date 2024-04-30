﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_subscription_info.h"

namespace mir3d
{
	class mrpc_subscription_info_cs : public RpcPacket 
	{

	public:
		mrpc_subscription_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::subscription_info_cs, tag)
		{
		}
		mrpc_subscription_info_cs() : RpcPacket(mpe_rpc_cmd::subscription_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_subscription_info_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		std::vector<mrpcs_subscription_info> subscription_info{};

	public:
		mrpc_subscription_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::subscription_info_sc, tag)
		{
		}
		mrpc_subscription_info_sc() : RpcPacket(mpe_rpc_cmd::subscription_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &subscription_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
