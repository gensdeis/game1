#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_cash_limited_product.h"

namespace mir3d
{
	class mrpc_cash_shop_limited_product_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_cash_limited_product> info{};

	public:
		mrpc_cash_shop_limited_product_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cash_shop_limited_product_cs, tag)
		{
		}
		mrpc_cash_shop_limited_product_cs() : RpcPacket(mpe_rpc_cmd::cash_shop_limited_product_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_cash_shop_limited_product_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_cash_shop_limited_product_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cash_shop_limited_product_sc, tag)
		{
		}
		mrpc_cash_shop_limited_product_sc() : RpcPacket(mpe_rpc_cmd::cash_shop_limited_product_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
