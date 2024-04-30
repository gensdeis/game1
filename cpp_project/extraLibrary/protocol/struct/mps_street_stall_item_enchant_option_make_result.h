#pragma once
#include <vector>
#include <string>
#include "mps_item_add.h"
#include "mps_enchant_option_list.h"

namespace mir3d
{
	class mps_street_stall_item_enchant_option_make_result 
	{
	public:
		int64_t iuid{};
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
	private:
		bool flag_option_list = false;
		mps_enchant_option_list option_list;
		mps_enchant_option_list* p_option_list = nullptr;
	public:
		bool has_option_list() const
		{
			return flag_option_list;
		}
		mps_enchant_option_list* alloc_option_list()
		{
			flag_option_list = true;
			return &option_list;
		}
		const mps_enchant_option_list* get_option_list() const
		{
			if (true == flag_option_list)
			{
				if (nullptr == p_option_list)
				{
					return &option_list;
				}
				return p_option_list;
			}
			return nullptr;
		}
		void set_option_list(mps_enchant_option_list* in_option_list)
		{
			if (nullptr == p_option_list)
			{
				p_option_list = in_option_list;
				flag_option_list = true;
			}
		}

	public:
		mps_street_stall_item_enchant_option_make_result()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_option_list);
			if (true == flag_option_list)
			{
				if (nullptr != p_option_list)
					protocol::SerializeType(pBuffer, p_option_list);
				else
					protocol::SerializeType(pBuffer, &option_list);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
