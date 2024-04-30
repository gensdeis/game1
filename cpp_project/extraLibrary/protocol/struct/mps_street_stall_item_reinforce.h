#pragma once
#include <vector>
#include <string>
#include "mps_item_iuid_list.h"

namespace mir3d
{
	class mps_street_stall_item_reinforce 
	{
	public:
		int64_t iuid{};
	public:
		mpe_item_reinforce_position flag{};
	private:
		bool flag_info = false;
		mps_item_iuid_list info;
		mps_item_iuid_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_iuid_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_iuid_list* get_info() const
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
		void set_info(mps_item_iuid_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		mpe_reinforce_stone_type stone_type{};

	public:
		mps_street_stall_item_reinforce()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeEnum(pBuffer, &stone_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
