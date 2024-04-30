#pragma once
#include <vector>
#include <string>
#include "mps_list_combo.h"

namespace mir3d
{
	class mrpcs_meridians 
	{
	public:
		std::string info{};
	private:
		bool flag_skill_slot = false;
		mps_list_combo skill_slot;
		mps_list_combo* p_skill_slot = nullptr;
	public:
		bool has_skill_slot() const
		{
			return flag_skill_slot;
		}
		mps_list_combo* alloc_skill_slot()
		{
			flag_skill_slot = true;
			return &skill_slot;
		}
		const mps_list_combo* get_skill_slot() const
		{
			if (true == flag_skill_slot)
			{
				if (nullptr == p_skill_slot)
				{
					return &skill_slot;
				}
				return p_skill_slot;
			}
			return nullptr;
		}
		void set_skill_slot(mps_list_combo* in_skill_slot)
		{
			if (nullptr == p_skill_slot)
			{
				p_skill_slot = in_skill_slot;
				flag_skill_slot = true;
			}
		}

	public:
		mrpcs_meridians()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &flag_skill_slot);
			if (true == flag_skill_slot)
			{
				if (nullptr != p_skill_slot)
					protocol::SerializeType(pBuffer, p_skill_slot);
				else
					protocol::SerializeType(pBuffer, &skill_slot);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
