#pragma once
#include <vector>
#include <string>
#include "mps_character_ability_stat.h"
#include "mps_character_ability_stat.h"

namespace mir3d
{
	class mps_character_ability 
	{
	private:
		bool flag_fish = false;
		mps_character_ability_stat fish;
		mps_character_ability_stat* p_fish = nullptr;
	public:
		bool has_fish() const
		{
			return flag_fish;
		}
		mps_character_ability_stat* alloc_fish()
		{
			flag_fish = true;
			return &fish;
		}
		const mps_character_ability_stat* get_fish() const
		{
			if (true == flag_fish)
			{
				if (nullptr == p_fish)
				{
					return &fish;
				}
				return p_fish;
			}
			return nullptr;
		}
		void set_fish(mps_character_ability_stat* in_fish)
		{
			if (nullptr == p_fish)
			{
				p_fish = in_fish;
				flag_fish = true;
			}
		}
	private:
		bool flag_collect = false;
		mps_character_ability_stat collect;
		mps_character_ability_stat* p_collect = nullptr;
	public:
		bool has_collect() const
		{
			return flag_collect;
		}
		mps_character_ability_stat* alloc_collect()
		{
			flag_collect = true;
			return &collect;
		}
		const mps_character_ability_stat* get_collect() const
		{
			if (true == flag_collect)
			{
				if (nullptr == p_collect)
				{
					return &collect;
				}
				return p_collect;
			}
			return nullptr;
		}
		void set_collect(mps_character_ability_stat* in_collect)
		{
			if (nullptr == p_collect)
			{
				p_collect = in_collect;
				flag_collect = true;
			}
		}

	public:
		mps_character_ability()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &flag_fish);
			if (true == flag_fish)
			{
				if (nullptr != p_fish)
					protocol::SerializeType(pBuffer, p_fish);
				else
					protocol::SerializeType(pBuffer, &fish);
			}
			protocol::SerializeType(pBuffer, &flag_collect);
			if (true == flag_collect)
			{
				if (nullptr != p_collect)
					protocol::SerializeType(pBuffer, p_collect);
				else
					protocol::SerializeType(pBuffer, &collect);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
