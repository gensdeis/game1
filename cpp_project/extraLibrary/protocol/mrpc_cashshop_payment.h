#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_cart_item.h"
#include "struct/mps_cash_shop_buy_count.h"
#include "struct/mps_seasonpass.h"
#include "struct/mps_cash_shop_buy_count.h"

namespace mir3d
{
	class mrpc_cashshop_payment_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		std::vector<mps_cart_item> cart_item{};
	public:
		std::vector<mps_cash_shop_buy_count> buy_count{};
	private:
		bool flag_buy_seasonpass = false;
		mps_seasonpass buy_seasonpass;
		mps_seasonpass* p_buy_seasonpass = nullptr;
	public:
		bool has_buy_seasonpass() const
		{
			return flag_buy_seasonpass;
		}
		mps_seasonpass* alloc_buy_seasonpass()
		{
			flag_buy_seasonpass = true;
			return &buy_seasonpass;
		}
		const mps_seasonpass* get_buy_seasonpass() const
		{
			if (true == flag_buy_seasonpass)
			{
				if (nullptr == p_buy_seasonpass)
				{
					return &buy_seasonpass;
				}
				return p_buy_seasonpass;
			}
			return nullptr;
		}
		void set_buy_seasonpass(mps_seasonpass* in_buy_seasonpass)
		{
			if (nullptr == p_buy_seasonpass)
			{
				p_buy_seasonpass = in_buy_seasonpass;
				flag_buy_seasonpass = true;
			}
		}
	private:
		bool flag_reset_item = false;
		mps_cash_shop_buy_count reset_item;
		mps_cash_shop_buy_count* p_reset_item = nullptr;
	public:
		bool has_reset_item() const
		{
			return flag_reset_item;
		}
		mps_cash_shop_buy_count* alloc_reset_item()
		{
			flag_reset_item = true;
			return &reset_item;
		}
		const mps_cash_shop_buy_count* get_reset_item() const
		{
			if (true == flag_reset_item)
			{
				if (nullptr == p_reset_item)
				{
					return &reset_item;
				}
				return p_reset_item;
			}
			return nullptr;
		}
		void set_reset_item(mps_cash_shop_buy_count* in_reset_item)
		{
			if (nullptr == p_reset_item)
			{
				p_reset_item = in_reset_item;
				flag_reset_item = true;
			}
		}
	public:
		bool wemix_payment{};

	public:
		mrpc_cashshop_payment_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cashshop_payment_cs, tag)
		{
		}
		mrpc_cashshop_payment_cs() : RpcPacket(mpe_rpc_cmd::cashshop_payment_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cart_item);
			protocol::SerializeType(pBuffer, &buy_count);
			protocol::SerializeType(pBuffer, &flag_buy_seasonpass);
			if (true == flag_buy_seasonpass)
			{
				if (nullptr != p_buy_seasonpass)
					protocol::SerializeType(pBuffer, p_buy_seasonpass);
				else
					protocol::SerializeType(pBuffer, &buy_seasonpass);
			}
			protocol::SerializeType(pBuffer, &flag_reset_item);
			if (true == flag_reset_item)
			{
				if (nullptr != p_reset_item)
					protocol::SerializeType(pBuffer, p_reset_item);
				else
					protocol::SerializeType(pBuffer, &reset_item);
			}
			protocol::SerializeType(pBuffer, &wemix_payment);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_cashshop_payment_sc : public RpcPacket 
	{

	public:
		mrpc_cashshop_payment_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cashshop_payment_sc, tag)
		{
		}
		mrpc_cashshop_payment_sc() : RpcPacket(mpe_rpc_cmd::cashshop_payment_sc)
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

}
