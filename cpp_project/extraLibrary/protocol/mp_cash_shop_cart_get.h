#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_cash_shop_buy_count.h"

namespace mir3d
{
	class mp_cash_shop_cart_get_cs : public BasePacket 
	{
	public:
		int64_t uid{};
	public:
		bool is_all{};

	public:
		mp_cash_shop_cart_get_cs() : BasePacket(mpe_cmd::cash_shop_cart_get_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &is_all);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_cash_shop_cart_get_sc : public BasePacket 
	{
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
		std::vector<int64_t> get_cart_item_list{};
	public:
		int32_t cash{};
	public:
		mpe_error result{};
	public:
		bool isFull{};
	public:
		std::vector<mps_cash_shop_buy_count> list_buy_count{};

	public:
		mp_cash_shop_cart_get_sc() : BasePacket(mpe_cmd::cash_shop_cart_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_get_item);
			if (true == flag_get_item)
			{
				if (nullptr != p_get_item)
					protocol::SerializeType(pBuffer, p_get_item);
				else
					protocol::SerializeType(pBuffer, &get_item);
			}
			protocol::SerializeType(pBuffer, &get_cart_item_list);
			protocol::SerializeType(pBuffer, &cash);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &isFull);
			protocol::SerializeType(pBuffer, &list_buy_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
