#pragma once
#include <vector>
#include <string>
#include "mrpcs_indun_character.h"

namespace mir3d
{
	class mrpcs_indun_character_list 
	{
	private:
		bool flag_list = false;
		mrpcs_indun_character list;
		mrpcs_indun_character* p_list = nullptr;
	public:
		bool has_list() const
		{
			return flag_list;
		}
		mrpcs_indun_character* alloc_list()
		{
			flag_list = true;
			return &list;
		}
		const mrpcs_indun_character* get_list() const
		{
			if (true == flag_list)
			{
				if (nullptr == p_list)
				{
					return &list;
				}
				return p_list;
			}
			return nullptr;
		}
		void set_list(mrpcs_indun_character* in_list)
		{
			if (nullptr == p_list)
			{
				p_list = in_list;
				flag_list = true;
			}
		}

	public:
		mrpcs_indun_character_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &flag_list);
			if (true == flag_list)
			{
				if (nullptr != p_list)
					protocol::SerializeType(pBuffer, p_list);
				else
					protocol::SerializeType(pBuffer, &list);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
