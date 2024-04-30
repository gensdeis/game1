﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_exchange_item_minprice.h"

namespace mir3d
{
	class mrpc_gm_exchange_item_minprice_update_cs : public RpcPacket 
	{

	public:
		mrpc_gm_exchange_item_minprice_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_exchange_item_minprice_update_cs, tag)
		{
		}
		mrpc_gm_exchange_item_minprice_update_cs() : RpcPacket(mpe_rpc_cmd::gm_exchange_item_minprice_update_cs)
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

	class mrpc_gm_exchange_item_minprice_update_sc : public RpcPacket 
	{
	public:
		std::vector<mrpcs_exchange_item_minprice> list{};

	public:
		mrpc_gm_exchange_item_minprice_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_exchange_item_minprice_update_sc, tag)
		{
		}
		mrpc_gm_exchange_item_minprice_update_sc() : RpcPacket(mpe_rpc_cmd::gm_exchange_item_minprice_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
