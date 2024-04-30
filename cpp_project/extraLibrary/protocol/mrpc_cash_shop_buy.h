#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_cart_item.h"
#include "struct/mps_obtain_pet_info.h"
#include "struct/mps_temp_pet.h"
#include "struct/mps_cash_info.h"
#include "struct/mps_cash_shop_buy_count.h"
#include "struct/mps_cash_package_product.h"
#include "struct/mps_seasonpass.h"
#include "struct/mps_obtain_avatar.h"
#include "struct/mps_obtain_reflection.h"
#include "struct/mps_temp_reflection.h"
#include "struct/mps_dictionary_info.h"
#include "struct/mps_item_add.h"
#include "struct/mps_cart_item.h"
#include "struct/mps_cash_shop_buy_count.h"
#include "struct/mps_obtain_pet_info.h"
#include "struct/mps_temp_pet.h"
#include "struct/mps_cash_package_product.h"
#include "struct/mps_seasonpass.h"
#include "struct/mps_obtain_avatar.h"
#include "struct/mps_obtain_reflection.h"
#include "struct/mps_temp_reflection.h"
#include "struct/mps_dictionary_info.h"

namespace mir3d
{
	class mrpc_cash_shop_buy_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	private:
		bool flag_buy_item = false;
		mps_item_add buy_item;	// 인벤에들어간상품
		mps_item_add* p_buy_item = nullptr;
	public:
		bool has_buy_item() const
		{
			return flag_buy_item;
		}
		mps_item_add* alloc_buy_item()
		{
			flag_buy_item = true;
			return &buy_item;
		}
		const mps_item_add* get_buy_item() const
		{
			if (true == flag_buy_item)
			{
				if (nullptr == p_buy_item)
				{
					return &buy_item;
				}
				return p_buy_item;
			}
			return nullptr;
		}
		void set_buy_item(mps_item_add* in_buy_item)
		{
			if (nullptr == p_buy_item)
			{
				p_buy_item = in_buy_item;
				flag_buy_item = true;
			}
		}
	public:
		std::vector<mps_cart_item> cart_item_list{};	// 보관함에들어온상품
	public:
		std::vector<mps_obtain_pet_info> pet_list{};
	public:
		std::vector<mps_temp_pet> list_temp_pet{};
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
	private:
		bool flag_buy_count = false;
		mps_cash_shop_buy_count buy_count;
		mps_cash_shop_buy_count* p_buy_count = nullptr;
	public:
		bool has_buy_count() const
		{
			return flag_buy_count;
		}
		mps_cash_shop_buy_count* alloc_buy_count()
		{
			flag_buy_count = true;
			return &buy_count;
		}
		const mps_cash_shop_buy_count* get_buy_count() const
		{
			if (true == flag_buy_count)
			{
				if (nullptr == p_buy_count)
				{
					return &buy_count;
				}
				return p_buy_count;
			}
			return nullptr;
		}
		void set_buy_count(mps_cash_shop_buy_count* in_buy_count)
		{
			if (nullptr == p_buy_count)
			{
				p_buy_count = in_buy_count;
				flag_buy_count = true;
			}
		}
	public:
		uint8_t total_buy_count{};
	public:
		bool is_limit{};	// 구매개수재한인가?
	public:
		uint16_t type{};	// 상품 카테고리 타입
	private:
		bool flag_package_product = false;
		mps_cash_package_product package_product;	// 꾸러미
		mps_cash_package_product* p_package_product = nullptr;
	public:
		bool has_package_product() const
		{
			return flag_package_product;
		}
		mps_cash_package_product* alloc_package_product()
		{
			flag_package_product = true;
			return &package_product;
		}
		const mps_cash_package_product* get_package_product() const
		{
			if (true == flag_package_product)
			{
				if (nullptr == p_package_product)
				{
					return &package_product;
				}
				return p_package_product;
			}
			return nullptr;
		}
		void set_package_product(mps_cash_package_product* in_package_product)
		{
			if (nullptr == p_package_product)
			{
				p_package_product = in_package_product;
				flag_package_product = true;
			}
		}
	private:
		bool flag_seasonpass = false;
		mps_seasonpass seasonpass;	// 시즌패스
		mps_seasonpass* p_seasonpass = nullptr;
	public:
		bool has_seasonpass() const
		{
			return flag_seasonpass;
		}
		mps_seasonpass* alloc_seasonpass()
		{
			flag_seasonpass = true;
			return &seasonpass;
		}
		const mps_seasonpass* get_seasonpass() const
		{
			if (true == flag_seasonpass)
			{
				if (nullptr == p_seasonpass)
				{
					return &seasonpass;
				}
				return p_seasonpass;
			}
			return nullptr;
		}
		void set_seasonpass(mps_seasonpass* in_seasonpass)
		{
			if (nullptr == p_seasonpass)
			{
				p_seasonpass = in_seasonpass;
				flag_seasonpass = true;
			}
		}
	public:
		std::vector<mps_obtain_avatar> avatar_list{};
	public:
		std::vector<mps_obtain_reflection> reflection_list{};
	public:
		std::vector<mps_temp_reflection> temp_reflection_list{};
	public:
		uint16_t limit_type{};	// 구매제한 타입
	public:
		std::vector<mps_dictionary_info> list_dic{};

	public:
		mrpc_cash_shop_buy_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cash_shop_buy_cs, tag)
		{
		}
		mrpc_cash_shop_buy_cs() : RpcPacket(mpe_rpc_cmd::cash_shop_buy_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &flag_buy_item);
			if (true == flag_buy_item)
			{
				if (nullptr != p_buy_item)
					protocol::SerializeType(pBuffer, p_buy_item);
				else
					protocol::SerializeType(pBuffer, &buy_item);
			}
			protocol::SerializeType(pBuffer, &cart_item_list);
			protocol::SerializeType(pBuffer, &pet_list);
			protocol::SerializeType(pBuffer, &list_temp_pet);
			protocol::SerializeType(pBuffer, &flag_cash_info);
			if (true == flag_cash_info)
			{
				if (nullptr != p_cash_info)
					protocol::SerializeType(pBuffer, p_cash_info);
				else
					protocol::SerializeType(pBuffer, &cash_info);
			}
			protocol::SerializeType(pBuffer, &flag_buy_count);
			if (true == flag_buy_count)
			{
				if (nullptr != p_buy_count)
					protocol::SerializeType(pBuffer, p_buy_count);
				else
					protocol::SerializeType(pBuffer, &buy_count);
			}
			protocol::SerializeType(pBuffer, &total_buy_count);
			protocol::SerializeType(pBuffer, &is_limit);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &flag_package_product);
			if (true == flag_package_product)
			{
				if (nullptr != p_package_product)
					protocol::SerializeType(pBuffer, p_package_product);
				else
					protocol::SerializeType(pBuffer, &package_product);
			}
			protocol::SerializeType(pBuffer, &flag_seasonpass);
			if (true == flag_seasonpass)
			{
				if (nullptr != p_seasonpass)
					protocol::SerializeType(pBuffer, p_seasonpass);
				else
					protocol::SerializeType(pBuffer, &seasonpass);
			}
			protocol::SerializeType(pBuffer, &avatar_list);
			protocol::SerializeType(pBuffer, &reflection_list);
			protocol::SerializeType(pBuffer, &temp_reflection_list);
			protocol::SerializeType(pBuffer, &limit_type);
			protocol::SerializeType(pBuffer, &list_dic);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_cash_shop_buy_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_buy_item = false;
		mps_item_add buy_item;	// 인벤에들어간상품
		mps_item_add* p_buy_item = nullptr;
	public:
		bool has_buy_item() const
		{
			return flag_buy_item;
		}
		mps_item_add* alloc_buy_item()
		{
			flag_buy_item = true;
			return &buy_item;
		}
		const mps_item_add* get_buy_item() const
		{
			if (true == flag_buy_item)
			{
				if (nullptr == p_buy_item)
				{
					return &buy_item;
				}
				return p_buy_item;
			}
			return nullptr;
		}
		void set_buy_item(mps_item_add* in_buy_item)
		{
			if (nullptr == p_buy_item)
			{
				p_buy_item = in_buy_item;
				flag_buy_item = true;
			}
		}
	public:
		std::vector<mps_cart_item> cart_item_list{};	// 보관함에들어온상품
	private:
		bool flag_buy_count = false;
		mps_cash_shop_buy_count buy_count;
		mps_cash_shop_buy_count* p_buy_count = nullptr;
	public:
		bool has_buy_count() const
		{
			return flag_buy_count;
		}
		mps_cash_shop_buy_count* alloc_buy_count()
		{
			flag_buy_count = true;
			return &buy_count;
		}
		const mps_cash_shop_buy_count* get_buy_count() const
		{
			if (true == flag_buy_count)
			{
				if (nullptr == p_buy_count)
				{
					return &buy_count;
				}
				return p_buy_count;
			}
			return nullptr;
		}
		void set_buy_count(mps_cash_shop_buy_count* in_buy_count)
		{
			if (nullptr == p_buy_count)
			{
				p_buy_count = in_buy_count;
				flag_buy_count = true;
			}
		}
	public:
		std::vector<mps_obtain_pet_info> pet_list{};
	public:
		std::vector<mps_temp_pet> list_temp_pet{};
	private:
		bool flag_package_product = false;
		mps_cash_package_product package_product;
		mps_cash_package_product* p_package_product = nullptr;
	public:
		bool has_package_product() const
		{
			return flag_package_product;
		}
		mps_cash_package_product* alloc_package_product()
		{
			flag_package_product = true;
			return &package_product;
		}
		const mps_cash_package_product* get_package_product() const
		{
			if (true == flag_package_product)
			{
				if (nullptr == p_package_product)
				{
					return &package_product;
				}
				return p_package_product;
			}
			return nullptr;
		}
		void set_package_product(mps_cash_package_product* in_package_product)
		{
			if (nullptr == p_package_product)
			{
				p_package_product = in_package_product;
				flag_package_product = true;
			}
		}
	private:
		bool flag_seasonpass = false;
		mps_seasonpass seasonpass;
		mps_seasonpass* p_seasonpass = nullptr;
	public:
		bool has_seasonpass() const
		{
			return flag_seasonpass;
		}
		mps_seasonpass* alloc_seasonpass()
		{
			flag_seasonpass = true;
			return &seasonpass;
		}
		const mps_seasonpass* get_seasonpass() const
		{
			if (true == flag_seasonpass)
			{
				if (nullptr == p_seasonpass)
				{
					return &seasonpass;
				}
				return p_seasonpass;
			}
			return nullptr;
		}
		void set_seasonpass(mps_seasonpass* in_seasonpass)
		{
			if (nullptr == p_seasonpass)
			{
				p_seasonpass = in_seasonpass;
				flag_seasonpass = true;
			}
		}
	public:
		std::vector<mps_obtain_avatar> avatar_list{};
	public:
		std::vector<mps_obtain_reflection> reflection_list{};
	public:
		std::vector<mps_temp_reflection> temp_reflection_list{};
	public:
		std::vector<mps_dictionary_info> list_dic{};

	public:
		mrpc_cash_shop_buy_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cash_shop_buy_sc, tag)
		{
		}
		mrpc_cash_shop_buy_sc() : RpcPacket(mpe_rpc_cmd::cash_shop_buy_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_buy_item);
			if (true == flag_buy_item)
			{
				if (nullptr != p_buy_item)
					protocol::SerializeType(pBuffer, p_buy_item);
				else
					protocol::SerializeType(pBuffer, &buy_item);
			}
			protocol::SerializeType(pBuffer, &cart_item_list);
			protocol::SerializeType(pBuffer, &flag_buy_count);
			if (true == flag_buy_count)
			{
				if (nullptr != p_buy_count)
					protocol::SerializeType(pBuffer, p_buy_count);
				else
					protocol::SerializeType(pBuffer, &buy_count);
			}
			protocol::SerializeType(pBuffer, &pet_list);
			protocol::SerializeType(pBuffer, &list_temp_pet);
			protocol::SerializeType(pBuffer, &flag_package_product);
			if (true == flag_package_product)
			{
				if (nullptr != p_package_product)
					protocol::SerializeType(pBuffer, p_package_product);
				else
					protocol::SerializeType(pBuffer, &package_product);
			}
			protocol::SerializeType(pBuffer, &flag_seasonpass);
			if (true == flag_seasonpass)
			{
				if (nullptr != p_seasonpass)
					protocol::SerializeType(pBuffer, p_seasonpass);
				else
					protocol::SerializeType(pBuffer, &seasonpass);
			}
			protocol::SerializeType(pBuffer, &avatar_list);
			protocol::SerializeType(pBuffer, &reflection_list);
			protocol::SerializeType(pBuffer, &temp_reflection_list);
			protocol::SerializeType(pBuffer, &list_dic);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
