#pragma once
#include <vector>
#include <string>
#include "mps_item_add.h"
#include "mps_list_quest.h"

namespace mir3d
{
	class mps_gameitem_update 
	{
	private:
		bool flag_item_info = false;
		mps_item_add item_info;
		mps_item_add* p_item_info = nullptr;
	public:
		bool has_item_info() const
		{
			return flag_item_info;
		}
		mps_item_add* alloc_item_info()
		{
			flag_item_info = true;
			return &item_info;
		}
		const mps_item_add* get_item_info() const
		{
			if (true == flag_item_info)
			{
				if (nullptr == p_item_info)
				{
					return &item_info;
				}
				return p_item_info;
			}
			return nullptr;
		}
		void set_item_info(mps_item_add* in_item_info)
		{
			if (nullptr == p_item_info)
			{
				p_item_info = in_item_info;
				flag_item_info = true;
			}
		}
	private:
		bool flag_quest_info = false;
		mps_list_quest quest_info;
		mps_list_quest* p_quest_info = nullptr;
	public:
		bool has_quest_info() const
		{
			return flag_quest_info;
		}
		mps_list_quest* alloc_quest_info()
		{
			flag_quest_info = true;
			return &quest_info;
		}
		const mps_list_quest* get_quest_info() const
		{
			if (true == flag_quest_info)
			{
				if (nullptr == p_quest_info)
				{
					return &quest_info;
				}
				return p_quest_info;
			}
			return nullptr;
		}
		void set_quest_info(mps_list_quest* in_quest_info)
		{
			if (nullptr == p_quest_info)
			{
				p_quest_info = in_quest_info;
				flag_quest_info = true;
			}
		}

	public:
		mps_gameitem_update()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &flag_item_info);
			if (true == flag_item_info)
			{
				if (nullptr != p_item_info)
					protocol::SerializeType(pBuffer, p_item_info);
				else
					protocol::SerializeType(pBuffer, &item_info);
			}
			protocol::SerializeType(pBuffer, &flag_quest_info);
			if (true == flag_quest_info)
			{
				if (nullptr != p_quest_info)
					protocol::SerializeType(pBuffer, p_quest_info);
				else
					protocol::SerializeType(pBuffer, &quest_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
