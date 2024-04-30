#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_cash_shop_buy_count.h"
#include "struct/mps_cart_item.h"
#include "struct/mps_cash_exchange_product.h"
#include "struct/mps_cash_package_product.h"

namespace mir3d
{
	class mrpc_cash_shop_info_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		bool redirect{};

	public:
		mrpc_cash_shop_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cash_shop_info_cs, tag)
		{
		}
		mrpc_cash_shop_info_cs() : RpcPacket(mpe_rpc_cmd::cash_shop_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &redirect);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_cash_shop_info_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_cash_shop_buy_count> buy_count_list{};
	public:
		std::vector<mps_cart_item> cart_item_list{};
	public:
		std::vector<mps_cash_exchange_product> exchange_product{};
	public:
		std::vector<mps_cash_package_product> package_product{};
	public:
		bool redirect{};

	public:
		mrpc_cash_shop_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cash_shop_info_sc, tag)
		{
		}
		mrpc_cash_shop_info_sc() : RpcPacket(mpe_rpc_cmd::cash_shop_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &buy_count_list);
			protocol::SerializeType(pBuffer, &cart_item_list);
			protocol::SerializeType(pBuffer, &exchange_product);
			protocol::SerializeType(pBuffer, &package_product);
			protocol::SerializeType(pBuffer, &redirect);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
