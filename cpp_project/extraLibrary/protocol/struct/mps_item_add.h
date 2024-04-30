#pragma once
#include <vector>
#include <string>
#include "mps_item_count_update.h"
#include "mps_update_goods.h"
#include "mps_item.h"
#include "mps_update_exp.h"

namespace mir3d
{
	class mps_item_add 
	{
	public:
		std::vector<mps_item_count_update> list_update{};	// //아이템추가되면서count변경된아이템들
	public:
		std::vector<mps_update_goods> list_goods{};	// //변경된재화
	public:
		std::vector<mps_item> list_item{};	// //item
	private:
		bool flag_update_exp = false;
		mps_update_exp update_exp;
		mps_update_exp* p_update_exp = nullptr;
	public:
		bool has_update_exp() const
		{
			return flag_update_exp;
		}
		mps_update_exp* alloc_update_exp()
		{
			flag_update_exp = true;
			return &update_exp;
		}
		const mps_update_exp* get_update_exp() const
		{
			if (true == flag_update_exp)
			{
				if (nullptr == p_update_exp)
				{
					return &update_exp;
				}
				return p_update_exp;
			}
			return nullptr;
		}
		void set_update_exp(mps_update_exp* in_update_exp)
		{
			if (nullptr == p_update_exp)
			{
				p_update_exp = in_update_exp;
				flag_update_exp = true;
			}
		}

	public:
		mps_item_add()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list_update);
			protocol::SerializeType(pBuffer, &list_goods);
			protocol::SerializeType(pBuffer, &list_item);
			protocol::SerializeType(pBuffer, &flag_update_exp);
			if (true == flag_update_exp)
			{
				if (nullptr != p_update_exp)
					protocol::SerializeType(pBuffer, p_update_exp);
				else
					protocol::SerializeType(pBuffer, &update_exp);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
