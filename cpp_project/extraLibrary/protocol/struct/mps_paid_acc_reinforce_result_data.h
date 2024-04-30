#pragma once
#include <vector>
#include <string>
#include "mps_item_option_update.h"

namespace mir3d
{
	class mps_paid_acc_reinforce_result_data 
	{
	public:
		mpe_reinforce_result result{};	// "아이템 강화 결과"
	private:
		bool flag_item_option = false;
		mps_item_option_update item_option;	// "아이템 정보 파괴된 경우 null"
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

	public:
		mps_paid_acc_reinforce_result_data()
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
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
