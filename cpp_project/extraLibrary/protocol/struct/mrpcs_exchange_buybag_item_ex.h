#pragma once
#include <vector>
#include <string>
#include "mps_exchange_buybag_item.h"

namespace mir3d
{
	class mrpcs_exchange_buybag_item_ex 
	{
	public:
		int64_t trade_cuid{};
	private:
		bool flag_item = false;
		mps_exchange_buybag_item item;
		mps_exchange_buybag_item* p_item = nullptr;
	public:
		bool has_item() const
		{
			return flag_item;
		}
		mps_exchange_buybag_item* alloc_item()
		{
			flag_item = true;
			return &item;
		}
		const mps_exchange_buybag_item* get_item() const
		{
			if (true == flag_item)
			{
				if (nullptr == p_item)
				{
					return &item;
				}
				return p_item;
			}
			return nullptr;
		}
		void set_item(mps_exchange_buybag_item* in_item)
		{
			if (nullptr == p_item)
			{
				p_item = in_item;
				flag_item = true;
			}
		}

	public:
		mrpcs_exchange_buybag_item_ex()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &trade_cuid);
			protocol::SerializeType(pBuffer, &flag_item);
			if (true == flag_item)
			{
				if (nullptr != p_item)
					protocol::SerializeType(pBuffer, p_item);
				else
					protocol::SerializeType(pBuffer, &item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
