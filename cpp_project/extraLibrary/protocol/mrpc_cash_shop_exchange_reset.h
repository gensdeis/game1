#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_cash_exchange_product.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_cash_shop_exchange_reset_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		mpe_cash_exchange_type reset_type{};
	private:
		bool flag_exchange_product = false;
		mps_cash_exchange_product exchange_product;
		mps_cash_exchange_product* p_exchange_product = nullptr;
	public:
		bool has_exchange_product() const
		{
			return flag_exchange_product;
		}
		mps_cash_exchange_product* alloc_exchange_product()
		{
			flag_exchange_product = true;
			return &exchange_product;
		}
		const mps_cash_exchange_product* get_exchange_product() const
		{
			if (true == flag_exchange_product)
			{
				if (nullptr == p_exchange_product)
				{
					return &exchange_product;
				}
				return p_exchange_product;
			}
			return nullptr;
		}
		void set_exchange_product(mps_cash_exchange_product* in_exchange_product)
		{
			if (nullptr == p_exchange_product)
			{
				p_exchange_product = in_exchange_product;
				flag_exchange_product = true;
			}
		}
	private:
		bool flag_item_add = false;
		mps_item_add item_add;
		mps_item_add* p_item_add = nullptr;
	public:
		bool has_item_add() const
		{
			return flag_item_add;
		}
		mps_item_add* alloc_item_add()
		{
			flag_item_add = true;
			return &item_add;
		}
		const mps_item_add* get_item_add() const
		{
			if (true == flag_item_add)
			{
				if (nullptr == p_item_add)
				{
					return &item_add;
				}
				return p_item_add;
			}
			return nullptr;
		}
		void set_item_add(mps_item_add* in_item_add)
		{
			if (nullptr == p_item_add)
			{
				p_item_add = in_item_add;
				flag_item_add = true;
			}
		}

	public:
		mrpc_cash_shop_exchange_reset_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cash_shop_exchange_reset_cs, tag)
		{
		}
		mrpc_cash_shop_exchange_reset_cs() : RpcPacket(mpe_rpc_cmd::cash_shop_exchange_reset_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeEnum(pBuffer, &reset_type);
			protocol::SerializeType(pBuffer, &flag_exchange_product);
			if (true == flag_exchange_product)
			{
				if (nullptr != p_exchange_product)
					protocol::SerializeType(pBuffer, p_exchange_product);
				else
					protocol::SerializeType(pBuffer, &exchange_product);
			}
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_cash_shop_exchange_reset_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_cash_shop_exchange_reset_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cash_shop_exchange_reset_sc, tag)
		{
		}
		mrpc_cash_shop_exchange_reset_sc() : RpcPacket(mpe_rpc_cmd::cash_shop_exchange_reset_sc)
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
