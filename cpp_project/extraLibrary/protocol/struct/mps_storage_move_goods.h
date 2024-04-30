#pragma once
#include <vector>
#include <string>
#include "mps_update_goods.h"

namespace mir3d
{
	class mps_storage_move_goods 
	{
	public:
		uint16_t storage_pos{};
	private:
		bool flag_goods = false;
		mps_update_goods goods;
		mps_update_goods* p_goods = nullptr;
	public:
		bool has_goods() const
		{
			return flag_goods;
		}
		mps_update_goods* alloc_goods()
		{
			flag_goods = true;
			return &goods;
		}
		const mps_update_goods* get_goods() const
		{
			if (true == flag_goods)
			{
				if (nullptr == p_goods)
				{
					return &goods;
				}
				return p_goods;
			}
			return nullptr;
		}
		void set_goods(mps_update_goods* in_goods)
		{
			if (nullptr == p_goods)
			{
				p_goods = in_goods;
				flag_goods = true;
			}
		}

	public:
		mps_storage_move_goods()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &storage_pos);
			protocol::SerializeType(pBuffer, &flag_goods);
			if (true == flag_goods)
			{
				if (nullptr != p_goods)
					protocol::SerializeType(pBuffer, p_goods);
				else
					protocol::SerializeType(pBuffer, &goods);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
