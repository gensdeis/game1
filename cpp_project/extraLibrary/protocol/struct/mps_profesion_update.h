#pragma once
#include <vector>
#include <string>
#include "mps_item_add.h"
#include "mps_profesion.h"
#include "mps_make_result.h"

namespace mir3d
{
	class mps_profesion_update 
	{
	private:
		bool flag_item = false;
		mps_item_add item;
		mps_item_add* p_item = nullptr;
	public:
		bool has_item() const
		{
			return flag_item;
		}
		mps_item_add* alloc_item()
		{
			flag_item = true;
			return &item;
		}
		const mps_item_add* get_item() const
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
		void set_item(mps_item_add* in_item)
		{
			if (nullptr == p_item)
			{
				p_item = in_item;
				flag_item = true;
			}
		}
	private:
		bool flag_update = false;
		mps_profesion update;
		mps_profesion* p_update = nullptr;
	public:
		bool has_update() const
		{
			return flag_update;
		}
		mps_profesion* alloc_update()
		{
			flag_update = true;
			return &update;
		}
		const mps_profesion* get_update() const
		{
			if (true == flag_update)
			{
				if (nullptr == p_update)
				{
					return &update;
				}
				return p_update;
			}
			return nullptr;
		}
		void set_update(mps_profesion* in_update)
		{
			if (nullptr == p_update)
			{
				p_update = in_update;
				flag_update = true;
			}
		}
	public:
		std::vector<uint8_t> list_result{};	// // mpe_make_result
	public:
		std::vector<mps_make_result> profesion_result{};	// 결과

	public:
		mps_profesion_update()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &flag_item);
			if (true == flag_item)
			{
				if (nullptr != p_item)
					protocol::SerializeType(pBuffer, p_item);
				else
					protocol::SerializeType(pBuffer, &item);
			}
			protocol::SerializeType(pBuffer, &flag_update);
			if (true == flag_update)
			{
				if (nullptr != p_update)
					protocol::SerializeType(pBuffer, p_update);
				else
					protocol::SerializeType(pBuffer, &update);
			}
			protocol::SerializeType(pBuffer, &list_result);
			protocol::SerializeType(pBuffer, &profesion_result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
