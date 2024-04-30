#pragma once
#include <vector>
#include <string>
#include "mps_item_option.h"

namespace mir3d
{
	class mps_item 
	{
	public:
		int64_t iuid{};
	public:
		int32_t id{};
	public:
		int32_t count{};
	public:
		bool locked{};
	public:
		bool have_option{};
	private:
		bool flag_option = false;
		mps_item_option option;
		mps_item_option* p_option = nullptr;
	public:
		bool has_option() const
		{
			return flag_option;
		}
		mps_item_option* alloc_option()
		{
			flag_option = true;
			return &option;
		}
		const mps_item_option* get_option() const
		{
			if (true == flag_option)
			{
				if (nullptr == p_option)
				{
					return &option;
				}
				return p_option;
			}
			return nullptr;
		}
		void set_option(mps_item_option* in_option)
		{
			if (nullptr == p_option)
			{
				p_option = in_option;
				flag_option = true;
			}
		}
	public:
		uint16_t durability{};
	public:
		uint16_t max_durability{};
	public:
		int32_t expire_time{};	// 초단위

	public:
		mps_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &locked);
			protocol::SerializeType(pBuffer, &have_option);
			protocol::SerializeType(pBuffer, &flag_option);
			if (true == flag_option)
			{
				if (nullptr != p_option)
					protocol::SerializeType(pBuffer, p_option);
				else
					protocol::SerializeType(pBuffer, &option);
			}
			protocol::SerializeType(pBuffer, &durability);
			protocol::SerializeType(pBuffer, &max_durability);
			protocol::SerializeType(pBuffer, &expire_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
