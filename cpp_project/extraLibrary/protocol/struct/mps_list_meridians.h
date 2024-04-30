#pragma once
#include <vector>
#include <string>
#include "mps_meridians.h"
#include "mps_list_combo.h"

namespace mir3d
{
	class mps_list_meridians 
	{
	public:
		std::vector<mps_meridians> list_meridians{};	// 경락
	private:
		bool flag_combo_info = false;
		mps_list_combo combo_info;	// 경락 스킬 슬롯
		mps_list_combo* p_combo_info = nullptr;
	public:
		bool has_combo_info() const
		{
			return flag_combo_info;
		}
		mps_list_combo* alloc_combo_info()
		{
			flag_combo_info = true;
			return &combo_info;
		}
		const mps_list_combo* get_combo_info() const
		{
			if (true == flag_combo_info)
			{
				if (nullptr == p_combo_info)
				{
					return &combo_info;
				}
				return p_combo_info;
			}
			return nullptr;
		}
		void set_combo_info(mps_list_combo* in_combo_info)
		{
			if (nullptr == p_combo_info)
			{
				p_combo_info = in_combo_info;
				flag_combo_info = true;
			}
		}

	public:
		mps_list_meridians()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list_meridians);
			protocol::SerializeType(pBuffer, &flag_combo_info);
			if (true == flag_combo_info)
			{
				if (nullptr != p_combo_info)
					protocol::SerializeType(pBuffer, p_combo_info);
				else
					protocol::SerializeType(pBuffer, &combo_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
