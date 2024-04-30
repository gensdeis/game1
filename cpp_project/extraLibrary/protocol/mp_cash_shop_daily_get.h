#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_cash_info.h"
#include "struct/mps_item_add.h"
#include "struct/mps_cash_package_product.h"
#include "struct/mps_cash_info.h"

namespace mir3d
{
	class mp_cash_shop_daily_get_cs : public BasePacket 
	{
	public:
		int32_t tid{};
	public:
		int32_t index{};
	public:
		int32_t sub_index{};
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
		mp_cash_shop_daily_get_cs() : BasePacket(mpe_cmd::cash_shop_daily_get_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &sub_index);
			protocol::SerializeType(pBuffer, &flag_cash_info);
			if (true == flag_cash_info)
			{
				if (nullptr != p_cash_info)
					protocol::SerializeType(pBuffer, p_cash_info);
				else
					protocol::SerializeType(pBuffer, &cash_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_cash_shop_daily_get_sc : public BasePacket 
	{
	private:
		bool flag_info_item = false;
		mps_item_add info_item;
		mps_item_add* p_info_item = nullptr;
	public:
		bool has_info_item() const
		{
			return flag_info_item;
		}
		mps_item_add* alloc_info_item()
		{
			flag_info_item = true;
			return &info_item;
		}
		const mps_item_add* get_info_item() const
		{
			if (true == flag_info_item)
			{
				if (nullptr == p_info_item)
				{
					return &info_item;
				}
				return p_info_item;
			}
			return nullptr;
		}
		void set_info_item(mps_item_add* in_info_item)
		{
			if (nullptr == p_info_item)
			{
				p_info_item = in_info_item;
				flag_info_item = true;
			}
		}
	private:
		bool flag_info_product = false;
		mps_cash_package_product info_product;
		mps_cash_package_product* p_info_product = nullptr;
	public:
		bool has_info_product() const
		{
			return flag_info_product;
		}
		mps_cash_package_product* alloc_info_product()
		{
			flag_info_product = true;
			return &info_product;
		}
		const mps_cash_package_product* get_info_product() const
		{
			if (true == flag_info_product)
			{
				if (nullptr == p_info_product)
				{
					return &info_product;
				}
				return p_info_product;
			}
			return nullptr;
		}
		void set_info_product(mps_cash_package_product* in_info_product)
		{
			if (nullptr == p_info_product)
			{
				p_info_product = in_info_product;
				flag_info_product = true;
			}
		}
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
		mp_cash_shop_daily_get_sc() : BasePacket(mpe_cmd::cash_shop_daily_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info_item);
			if (true == flag_info_item)
			{
				if (nullptr != p_info_item)
					protocol::SerializeType(pBuffer, p_info_item);
				else
					protocol::SerializeType(pBuffer, &info_item);
			}
			protocol::SerializeType(pBuffer, &flag_info_product);
			if (true == flag_info_product)
			{
				if (nullptr != p_info_product)
					protocol::SerializeType(pBuffer, p_info_product);
				else
					protocol::SerializeType(pBuffer, &info_product);
			}
			protocol::SerializeType(pBuffer, &flag_cash_info);
			if (true == flag_cash_info)
			{
				if (nullptr != p_cash_info)
					protocol::SerializeType(pBuffer, p_cash_info);
				else
					protocol::SerializeType(pBuffer, &cash_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
