#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_cash_shop_buy_count.h"
#include "struct/mps_cart_item.h"
#include "struct/mps_cash_info.h"
#include "struct/mps_cash_exchange_product.h"
#include "struct/mps_cash_package_product.h"
#include "struct/mps_cash_limited_product.h"
#include "struct/mps_seasonpass.h"

namespace mir3d
{
	class mweb_cash_shop_info_cs : public WebBasePacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mweb_cash_shop_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_cash_shop_info_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_cash_shop_buy_count> buy_count_list{};
	public:
		std::vector<mps_cart_item> cart_item_list{};
	private:
		bool flag_cash_info = false;
		mps_cash_info cash_info;
		mps_cash_info* p_cash_info = nullptr;
	public:
		bool has_cash_info() const
		{
			return flag_cash_info;
		}
		mps_cash_info* alloc_cash_info()
		{
			flag_cash_info = true;
			return &cash_info;
		}
		const mps_cash_info* get_cash_info() const
		{
			if (true == flag_cash_info)
			{
				if (nullptr == p_cash_info)
				{
					return &cash_info;
				}
				return p_cash_info;
			}
			return nullptr;
		}
		void set_cash_info(mps_cash_info* in_cash_info)
		{
			if (nullptr == p_cash_info)
			{
				p_cash_info = in_cash_info;
				flag_cash_info = true;
			}
		}
	public:
		std::vector<mps_cash_exchange_product> exchange_product{};	// 교환소 가능 품목
	public:
		std::vector<mps_cash_package_product> package_product{};	// 꾸러미 목록
	public:
		std::vector<mps_cash_limited_product> limited_product_list{};
	public:
		std::vector<mps_seasonpass> seasonpass_list{};
	public:
		int32_t character_level{};
	public:
		int64_t guid{};
	public:
		uint16_t league{};
	public:
		int32_t server_time{};
	public:
		int32_t time_zone{};
	public:
		int32_t result{};

	public:
		mweb_cash_shop_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &buy_count_list);
			protocol::SerializeType(pBuffer, &cart_item_list);
			protocol::SerializeType(pBuffer, &flag_cash_info);
			if (true == flag_cash_info)
			{
				if (nullptr != p_cash_info)
					protocol::SerializeType(pBuffer, p_cash_info);
				else
					protocol::SerializeType(pBuffer, &cash_info);
			}
			protocol::SerializeType(pBuffer, &exchange_product);
			protocol::SerializeType(pBuffer, &package_product);
			protocol::SerializeType(pBuffer, &limited_product_list);
			protocol::SerializeType(pBuffer, &seasonpass_list);
			protocol::SerializeType(pBuffer, &character_level);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &league);
			protocol::SerializeType(pBuffer, &server_time);
			protocol::SerializeType(pBuffer, &time_zone);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
