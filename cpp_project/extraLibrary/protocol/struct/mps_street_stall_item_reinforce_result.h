﻿#pragma once
#include <vector>
#include <string>
#include "mps_item_option_update.h"
#include "mps_item_add.h"
#include "mps_restore_item.h"

namespace mir3d
{
	class mps_street_stall_item_reinforce_result 
	{
	public:
		mpe_reinforce_result result{};
	private:
		bool flag_item_option = false;
		mps_item_option_update item_option;
		mps_item_option_update* p_item_option = nullptr;
	public:
		bool has_item_option() const
		{
			return flag_item_option;
		}
		mps_item_option_update* alloc_item_option()
		{
			flag_item_option = true;
			return &item_option;
		}
		const mps_item_option_update* get_item_option() const
		{
			if (true == flag_item_option)
			{
				if (nullptr == p_item_option)
				{
					return &item_option;
				}
				return p_item_option;
			}
			return nullptr;
		}
		void set_item_option(mps_item_option_update* in_item_option)
		{
			if (nullptr == p_item_option)
			{
				p_item_option = in_item_option;
				flag_item_option = true;
			}
		}
	private:
		bool flag_info = false;
		mps_item_add info;
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		uint16_t max_durability{};	// 생활장비 최대 내구도
	private:
		bool flag_restore_info = false;
		mps_restore_item restore_info;	// 신룡의축복
		mps_restore_item* p_restore_info = nullptr;
	public:
		bool has_restore_info() const
		{
			return flag_restore_info;
		}
		mps_restore_item* alloc_restore_info()
		{
			flag_restore_info = true;
			return &restore_info;
		}
		const mps_restore_item* get_restore_info() const
		{
			if (true == flag_restore_info)
			{
				if (nullptr == p_restore_info)
				{
					return &restore_info;
				}
				return p_restore_info;
			}
			return nullptr;
		}
		void set_restore_info(mps_restore_item* in_restore_info)
		{
			if (nullptr == p_restore_info)
			{
				p_restore_info = in_restore_info;
				flag_restore_info = true;
			}
		}

	public:
		mps_street_stall_item_reinforce_result()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_item_option);
			if (true == flag_item_option)
			{
				if (nullptr != p_item_option)
					protocol::SerializeType(pBuffer, p_item_option);
				else
					protocol::SerializeType(pBuffer, &item_option);
			}
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &max_durability);
			protocol::SerializeType(pBuffer, &flag_restore_info);
			if (true == flag_restore_info)
			{
				if (nullptr != p_restore_info)
					protocol::SerializeType(pBuffer, p_restore_info);
				else
					protocol::SerializeType(pBuffer, &restore_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}