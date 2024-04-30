#pragma once
#include <vector>
#include <string>
#include "mps_item_option.h"

namespace mir3d
{
	class mps_item_option_update 
	{
	public:
		int64_t iuid{};
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
		mps_item_option_update()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &flag_option);
			if (true == flag_option)
			{
				if (nullptr != p_option)
					protocol::SerializeType(pBuffer, p_option);
				else
					protocol::SerializeType(pBuffer, &option);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
