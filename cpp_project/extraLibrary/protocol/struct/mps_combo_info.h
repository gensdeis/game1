#pragma once
#include <vector>
#include <string>
#include "mps_combo_ability.h"

namespace mir3d
{
	class mps_combo_info 
	{
	public:
		int32_t slot_grade{};	// 슬롯 등급
	public:
		int32_t skill_id{};	// 장착 스킬 id
	private:
		bool flag_ability = false;
		mps_combo_ability ability;	// 슬롯 효과목록
		mps_combo_ability* p_ability = nullptr;
	public:
		bool has_ability() const
		{
			return flag_ability;
		}
		mps_combo_ability* alloc_ability()
		{
			flag_ability = true;
			return &ability;
		}
		const mps_combo_ability* get_ability() const
		{
			if (true == flag_ability)
			{
				if (nullptr == p_ability)
				{
					return &ability;
				}
				return p_ability;
			}
			return nullptr;
		}
		void set_ability(mps_combo_ability* in_ability)
		{
			if (nullptr == p_ability)
			{
				p_ability = in_ability;
				flag_ability = true;
			}
		}

	public:
		mps_combo_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &slot_grade);
			protocol::SerializeType(pBuffer, &skill_id);
			protocol::SerializeType(pBuffer, &flag_ability);
			if (true == flag_ability)
			{
				if (nullptr != p_ability)
					protocol::SerializeType(pBuffer, p_ability);
				else
					protocol::SerializeType(pBuffer, &ability);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
