#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_cart_item.h"
#include "struct/mrpcs_cash_cart_count.h"
#include "struct/mrpcs_cash_cart_count.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_cash_shop_cart_get_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<int64_t> cart_uid_list{};
	private:
		bool flag_get_item = false;
		mps_item_add get_item;
		mps_item_add* p_get_item = nullptr;
	public:
		bool has_get_item() const
		{
			return flag_get_item;
		}
		mps_item_add* alloc_get_item()
		{
			flag_get_item = true;
			return &get_item;
		}
		const mps_item_add* get_get_item() const
		{
			if (true == flag_get_item)
			{
				if (nullptr == p_get_item)
				{
					return &get_item;
				}
				return p_get_item;
			}
			return nullptr;
		}
		void set_get_item(mps_item_add* in_get_item)
		{
			if (nullptr == p_get_item)
			{
				p_get_item = in_get_item;
				flag_get_item = true;
			}
		}
	public:
		int32_t cash{};
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		bool isFull{};
	public:
		std::vector<mps_cart_item> db_account_cart_item{};
	public:
		std::vector<int64_t> db_account_uid_list{};
	public:
		std::vector<mrpcs_cash_cart_count> account_buy_list{};	// 계정구매갱신 목록
	public:
		std::vector<mrpcs_cash_cart_count> buy_list{};	// "서버,캐릭터 갱신 목록"

	public:
		mrpc_cash_shop_cart_get_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cash_shop_cart_get_cs, tag)
		{
		}
		mrpc_cash_shop_cart_get_cs() : RpcPacket(mpe_rpc_cmd::cash_shop_cart_get_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cart_uid_list);
			protocol::SerializeType(pBuffer, &flag_get_item);
			if (true == flag_get_item)
			{
				if (nullptr != p_get_item)
					protocol::SerializeType(pBuffer, p_get_item);
				else
					protocol::SerializeType(pBuffer, &get_item);
			}
			protocol::SerializeType(pBuffer, &cash);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &isFull);
			protocol::SerializeType(pBuffer, &db_account_cart_item);
			protocol::SerializeType(pBuffer, &db_account_uid_list);
			protocol::SerializeType(pBuffer, &account_buy_list);
			protocol::SerializeType(pBuffer, &buy_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_cash_shop_cart_get_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_get_item = false;
		mps_item_add get_item;
		mps_item_add* p_get_item = nullptr;
	public:
		bool has_get_item() const
		{
			return flag_get_item;
		}
		mps_item_add* alloc_get_item()
		{
			flag_get_item = true;
			return &get_item;
		}
		const mps_item_add* get_get_item() const
		{
			if (true == flag_get_item)
			{
				if (nullptr == p_get_item)
				{
					return &get_item;
				}
				return p_get_item;
			}
			return nullptr;
		}
		void set_get_item(mps_item_add* in_get_item)
		{
			if (nullptr == p_get_item)
			{
				p_get_item = in_get_item;
				flag_get_item = true;
			}
		}
	public:
		std::vector<int64_t> cart_uid_list{};
	public:
		bool isFull{};

	public:
		mrpc_cash_shop_cart_get_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cash_shop_cart_get_sc, tag)
		{
		}
		mrpc_cash_shop_cart_get_sc() : RpcPacket(mpe_rpc_cmd::cash_shop_cart_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_get_item);
			if (true == flag_get_item)
			{
				if (nullptr != p_get_item)
					protocol::SerializeType(pBuffer, p_get_item);
				else
					protocol::SerializeType(pBuffer, &get_item);
			}
			protocol::SerializeType(pBuffer, &cart_uid_list);
			protocol::SerializeType(pBuffer, &isFull);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
