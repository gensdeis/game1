#pragma once
#include <vector>
#include <string>
#include "mps_zone_info.h"
#include "mps_skillbook.h"
#include "mps_character_stat.h"
#include "mps_daily_content.h"
#include "mps_list_quest.h"
#include "mps_list_dungeon.h"
#include "mps_list_item_durability.h"
#include "mps_list_db_buff.h"
#include "mrpcs_vehicle_autosave.h"
#include "mps_list_pet_info.h"
#include "mrpcs_character_ranking_info.h"
#include "mrpcs_list_profesion_ranking.h"
#include "mrpcs_achieve_list.h"
#include "mrpcs_list_seasonpass_challenge.h"
#include "mps_illusion_dungeon.h"

namespace mir3d
{
	class mrpcs_character_autosave 
	{
	private:
		bool flag_zone = false;
		mps_zone_info zone;
		mps_zone_info* p_zone = nullptr;
	public:
		bool has_zone() const
		{
			return flag_zone;
		}
		mps_zone_info* alloc_zone()
		{
			flag_zone = true;
			return &zone;
		}
		const mps_zone_info* get_zone() const
		{
			if (true == flag_zone)
			{
				if (nullptr == p_zone)
				{
					return &zone;
				}
				return p_zone;
			}
			return nullptr;
		}
		void set_zone(mps_zone_info* in_zone)
		{
			if (nullptr == p_zone)
			{
				p_zone = in_zone;
				flag_zone = true;
			}
		}
	public:
		std::vector<int32_t> list_goods{};
	private:
		bool flag_skill = false;
		mps_skillbook skill;
		mps_skillbook* p_skill = nullptr;
	public:
		bool has_skill() const
		{
			return flag_skill;
		}
		mps_skillbook* alloc_skill()
		{
			flag_skill = true;
			return &skill;
		}
		const mps_skillbook* get_skill() const
		{
			if (true == flag_skill)
			{
				if (nullptr == p_skill)
				{
					return &skill;
				}
				return p_skill;
			}
			return nullptr;
		}
		void set_skill(mps_skillbook* in_skill)
		{
			if (nullptr == p_skill)
			{
				p_skill = in_skill;
				flag_skill = true;
			}
		}
	private:
		bool flag_stat = false;
		mps_character_stat stat;
		mps_character_stat* p_stat = nullptr;
	public:
		bool has_stat() const
		{
			return flag_stat;
		}
		mps_character_stat* alloc_stat()
		{
			flag_stat = true;
			return &stat;
		}
		const mps_character_stat* get_stat() const
		{
			if (true == flag_stat)
			{
				if (nullptr == p_stat)
				{
					return &stat;
				}
				return p_stat;
			}
			return nullptr;
		}
		void set_stat(mps_character_stat* in_stat)
		{
			if (nullptr == p_stat)
			{
				p_stat = in_stat;
				flag_stat = true;
			}
		}
	public:
		std::vector<int32_t> list_daily_content{};
	private:
		bool flag_daily_content = false;
		mps_daily_content daily_content;
		mps_daily_content* p_daily_content = nullptr;
	public:
		bool has_daily_content() const
		{
			return flag_daily_content;
		}
		mps_daily_content* alloc_daily_content()
		{
			flag_daily_content = true;
			return &daily_content;
		}
		const mps_daily_content* get_daily_content() const
		{
			if (true == flag_daily_content)
			{
				if (nullptr == p_daily_content)
				{
					return &daily_content;
				}
				return p_daily_content;
			}
			return nullptr;
		}
		void set_daily_content(mps_daily_content* in_daily_content)
		{
			if (nullptr == p_daily_content)
			{
				p_daily_content = in_daily_content;
				flag_daily_content = true;
			}
		}
	private:
		bool flag_list_quest = false;
		mps_list_quest list_quest;
		mps_list_quest* p_list_quest = nullptr;
	public:
		bool has_list_quest() const
		{
			return flag_list_quest;
		}
		mps_list_quest* alloc_list_quest()
		{
			flag_list_quest = true;
			return &list_quest;
		}
		const mps_list_quest* get_list_quest() const
		{
			if (true == flag_list_quest)
			{
				if (nullptr == p_list_quest)
				{
					return &list_quest;
				}
				return p_list_quest;
			}
			return nullptr;
		}
		void set_list_quest(mps_list_quest* in_list_quest)
		{
			if (nullptr == p_list_quest)
			{
				p_list_quest = in_list_quest;
				flag_list_quest = true;
			}
		}
	private:
		bool flag_list_dungeon = false;
		mps_list_dungeon list_dungeon;
		mps_list_dungeon* p_list_dungeon = nullptr;
	public:
		bool has_list_dungeon() const
		{
			return flag_list_dungeon;
		}
		mps_list_dungeon* alloc_list_dungeon()
		{
			flag_list_dungeon = true;
			return &list_dungeon;
		}
		const mps_list_dungeon* get_list_dungeon() const
		{
			if (true == flag_list_dungeon)
			{
				if (nullptr == p_list_dungeon)
				{
					return &list_dungeon;
				}
				return p_list_dungeon;
			}
			return nullptr;
		}
		void set_list_dungeon(mps_list_dungeon* in_list_dungeon)
		{
			if (nullptr == p_list_dungeon)
			{
				p_list_dungeon = in_list_dungeon;
				flag_list_dungeon = true;
			}
		}
	private:
		bool flag_list_item_durability = false;
		mps_list_item_durability list_item_durability;
		mps_list_item_durability* p_list_item_durability = nullptr;
	public:
		bool has_list_item_durability() const
		{
			return flag_list_item_durability;
		}
		mps_list_item_durability* alloc_list_item_durability()
		{
			flag_list_item_durability = true;
			return &list_item_durability;
		}
		const mps_list_item_durability* get_list_item_durability() const
		{
			if (true == flag_list_item_durability)
			{
				if (nullptr == p_list_item_durability)
				{
					return &list_item_durability;
				}
				return p_list_item_durability;
			}
			return nullptr;
		}
		void set_list_item_durability(mps_list_item_durability* in_list_item_durability)
		{
			if (nullptr == p_list_item_durability)
			{
				p_list_item_durability = in_list_item_durability;
				flag_list_item_durability = true;
			}
		}
	public:
		std::vector<int32_t> list_special_move{};
	private:
		bool flag_list_buff = false;
		mps_list_db_buff list_buff;
		mps_list_db_buff* p_list_buff = nullptr;
	public:
		bool has_list_buff() const
		{
			return flag_list_buff;
		}
		mps_list_db_buff* alloc_list_buff()
		{
			flag_list_buff = true;
			return &list_buff;
		}
		const mps_list_db_buff* get_list_buff() const
		{
			if (true == flag_list_buff)
			{
				if (nullptr == p_list_buff)
				{
					return &list_buff;
				}
				return p_list_buff;
			}
			return nullptr;
		}
		void set_list_buff(mps_list_db_buff* in_list_buff)
		{
			if (nullptr == p_list_buff)
			{
				p_list_buff = in_list_buff;
				flag_list_buff = true;
			}
		}
	private:
		bool flag_vehicle = false;
		mrpcs_vehicle_autosave vehicle;
		mrpcs_vehicle_autosave* p_vehicle = nullptr;
	public:
		bool has_vehicle() const
		{
			return flag_vehicle;
		}
		mrpcs_vehicle_autosave* alloc_vehicle()
		{
			flag_vehicle = true;
			return &vehicle;
		}
		const mrpcs_vehicle_autosave* get_vehicle() const
		{
			if (true == flag_vehicle)
			{
				if (nullptr == p_vehicle)
				{
					return &vehicle;
				}
				return p_vehicle;
			}
			return nullptr;
		}
		void set_vehicle(mrpcs_vehicle_autosave* in_vehicle)
		{
			if (nullptr == p_vehicle)
			{
				p_vehicle = in_vehicle;
				flag_vehicle = true;
			}
		}
	private:
		bool flag_list_pet_info = false;
		mps_list_pet_info list_pet_info;
		mps_list_pet_info* p_list_pet_info = nullptr;
	public:
		bool has_list_pet_info() const
		{
			return flag_list_pet_info;
		}
		mps_list_pet_info* alloc_list_pet_info()
		{
			flag_list_pet_info = true;
			return &list_pet_info;
		}
		const mps_list_pet_info* get_list_pet_info() const
		{
			if (true == flag_list_pet_info)
			{
				if (nullptr == p_list_pet_info)
				{
					return &list_pet_info;
				}
				return p_list_pet_info;
			}
			return nullptr;
		}
		void set_list_pet_info(mps_list_pet_info* in_list_pet_info)
		{
			if (nullptr == p_list_pet_info)
			{
				p_list_pet_info = in_list_pet_info;
				flag_list_pet_info = true;
			}
		}
	private:
		bool flag_character_ranking_info = false;
		mrpcs_character_ranking_info character_ranking_info;
		mrpcs_character_ranking_info* p_character_ranking_info = nullptr;
	public:
		bool has_character_ranking_info() const
		{
			return flag_character_ranking_info;
		}
		mrpcs_character_ranking_info* alloc_character_ranking_info()
		{
			flag_character_ranking_info = true;
			return &character_ranking_info;
		}
		const mrpcs_character_ranking_info* get_character_ranking_info() const
		{
			if (true == flag_character_ranking_info)
			{
				if (nullptr == p_character_ranking_info)
				{
					return &character_ranking_info;
				}
				return p_character_ranking_info;
			}
			return nullptr;
		}
		void set_character_ranking_info(mrpcs_character_ranking_info* in_character_ranking_info)
		{
			if (nullptr == p_character_ranking_info)
			{
				p_character_ranking_info = in_character_ranking_info;
				flag_character_ranking_info = true;
			}
		}
	private:
		bool flag_list_profesion_ranking = false;
		mrpcs_list_profesion_ranking list_profesion_ranking;
		mrpcs_list_profesion_ranking* p_list_profesion_ranking = nullptr;
	public:
		bool has_list_profesion_ranking() const
		{
			return flag_list_profesion_ranking;
		}
		mrpcs_list_profesion_ranking* alloc_list_profesion_ranking()
		{
			flag_list_profesion_ranking = true;
			return &list_profesion_ranking;
		}
		const mrpcs_list_profesion_ranking* get_list_profesion_ranking() const
		{
			if (true == flag_list_profesion_ranking)
			{
				if (nullptr == p_list_profesion_ranking)
				{
					return &list_profesion_ranking;
				}
				return p_list_profesion_ranking;
			}
			return nullptr;
		}
		void set_list_profesion_ranking(mrpcs_list_profesion_ranking* in_list_profesion_ranking)
		{
			if (nullptr == p_list_profesion_ranking)
			{
				p_list_profesion_ranking = in_list_profesion_ranking;
				flag_list_profesion_ranking = true;
			}
		}
	private:
		bool flag_list_achieve = false;
		mrpcs_achieve_list list_achieve;
		mrpcs_achieve_list* p_list_achieve = nullptr;
	public:
		bool has_list_achieve() const
		{
			return flag_list_achieve;
		}
		mrpcs_achieve_list* alloc_list_achieve()
		{
			flag_list_achieve = true;
			return &list_achieve;
		}
		const mrpcs_achieve_list* get_list_achieve() const
		{
			if (true == flag_list_achieve)
			{
				if (nullptr == p_list_achieve)
				{
					return &list_achieve;
				}
				return p_list_achieve;
			}
			return nullptr;
		}
		void set_list_achieve(mrpcs_achieve_list* in_list_achieve)
		{
			if (nullptr == p_list_achieve)
			{
				p_list_achieve = in_list_achieve;
				flag_list_achieve = true;
			}
		}
	public:
		short pet_team{};
	private:
		bool flag_list_challenge = false;
		mrpcs_list_seasonpass_challenge list_challenge;
		mrpcs_list_seasonpass_challenge* p_list_challenge = nullptr;
	public:
		bool has_list_challenge() const
		{
			return flag_list_challenge;
		}
		mrpcs_list_seasonpass_challenge* alloc_list_challenge()
		{
			flag_list_challenge = true;
			return &list_challenge;
		}
		const mrpcs_list_seasonpass_challenge* get_list_challenge() const
		{
			if (true == flag_list_challenge)
			{
				if (nullptr == p_list_challenge)
				{
					return &list_challenge;
				}
				return p_list_challenge;
			}
			return nullptr;
		}
		void set_list_challenge(mrpcs_list_seasonpass_challenge* in_list_challenge)
		{
			if (nullptr == p_list_challenge)
			{
				p_list_challenge = in_list_challenge;
				flag_list_challenge = true;
			}
		}
	public:
		int32_t cumulative_connection_time{};
	public:
		std::vector<int32_t> worship_info{};
	private:
		bool flag_illusion_dungeon = false;
		mps_illusion_dungeon illusion_dungeon;
		mps_illusion_dungeon* p_illusion_dungeon = nullptr;
	public:
		bool has_illusion_dungeon() const
		{
			return flag_illusion_dungeon;
		}
		mps_illusion_dungeon* alloc_illusion_dungeon()
		{
			flag_illusion_dungeon = true;
			return &illusion_dungeon;
		}
		const mps_illusion_dungeon* get_illusion_dungeon() const
		{
			if (true == flag_illusion_dungeon)
			{
				if (nullptr == p_illusion_dungeon)
				{
					return &illusion_dungeon;
				}
				return p_illusion_dungeon;
			}
			return nullptr;
		}
		void set_illusion_dungeon(mps_illusion_dungeon* in_illusion_dungeon)
		{
			if (nullptr == p_illusion_dungeon)
			{
				p_illusion_dungeon = in_illusion_dungeon;
				flag_illusion_dungeon = true;
			}
		}
	public:
		uint8_t field_boss_kill_count{};
	public:
		uint8_t arena_join_count{};
	public:
		int64_t exp{};
	public:
		int64_t expert_exp{};

	public:
		mrpcs_character_autosave()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &flag_zone);
			if (true == flag_zone)
			{
				if (nullptr != p_zone)
					protocol::SerializeType(pBuffer, p_zone);
				else
					protocol::SerializeType(pBuffer, &zone);
			}
			protocol::SerializeType(pBuffer, &list_goods);
			protocol::SerializeType(pBuffer, &flag_skill);
			if (true == flag_skill)
			{
				if (nullptr != p_skill)
					protocol::SerializeType(pBuffer, p_skill);
				else
					protocol::SerializeType(pBuffer, &skill);
			}
			protocol::SerializeType(pBuffer, &flag_stat);
			if (true == flag_stat)
			{
				if (nullptr != p_stat)
					protocol::SerializeType(pBuffer, p_stat);
				else
					protocol::SerializeType(pBuffer, &stat);
			}
			protocol::SerializeType(pBuffer, &list_daily_content);
			protocol::SerializeType(pBuffer, &flag_daily_content);
			if (true == flag_daily_content)
			{
				if (nullptr != p_daily_content)
					protocol::SerializeType(pBuffer, p_daily_content);
				else
					protocol::SerializeType(pBuffer, &daily_content);
			}
			protocol::SerializeType(pBuffer, &flag_list_quest);
			if (true == flag_list_quest)
			{
				if (nullptr != p_list_quest)
					protocol::SerializeType(pBuffer, p_list_quest);
				else
					protocol::SerializeType(pBuffer, &list_quest);
			}
			protocol::SerializeType(pBuffer, &flag_list_dungeon);
			if (true == flag_list_dungeon)
			{
				if (nullptr != p_list_dungeon)
					protocol::SerializeType(pBuffer, p_list_dungeon);
				else
					protocol::SerializeType(pBuffer, &list_dungeon);
			}
			protocol::SerializeType(pBuffer, &flag_list_item_durability);
			if (true == flag_list_item_durability)
			{
				if (nullptr != p_list_item_durability)
					protocol::SerializeType(pBuffer, p_list_item_durability);
				else
					protocol::SerializeType(pBuffer, &list_item_durability);
			}
			protocol::SerializeType(pBuffer, &list_special_move);
			protocol::SerializeType(pBuffer, &flag_list_buff);
			if (true == flag_list_buff)
			{
				if (nullptr != p_list_buff)
					protocol::SerializeType(pBuffer, p_list_buff);
				else
					protocol::SerializeType(pBuffer, &list_buff);
			}
			protocol::SerializeType(pBuffer, &flag_vehicle);
			if (true == flag_vehicle)
			{
				if (nullptr != p_vehicle)
					protocol::SerializeType(pBuffer, p_vehicle);
				else
					protocol::SerializeType(pBuffer, &vehicle);
			}
			protocol::SerializeType(pBuffer, &flag_list_pet_info);
			if (true == flag_list_pet_info)
			{
				if (nullptr != p_list_pet_info)
					protocol::SerializeType(pBuffer, p_list_pet_info);
				else
					protocol::SerializeType(pBuffer, &list_pet_info);
			}
			protocol::SerializeType(pBuffer, &flag_character_ranking_info);
			if (true == flag_character_ranking_info)
			{
				if (nullptr != p_character_ranking_info)
					protocol::SerializeType(pBuffer, p_character_ranking_info);
				else
					protocol::SerializeType(pBuffer, &character_ranking_info);
			}
			protocol::SerializeType(pBuffer, &flag_list_profesion_ranking);
			if (true == flag_list_profesion_ranking)
			{
				if (nullptr != p_list_profesion_ranking)
					protocol::SerializeType(pBuffer, p_list_profesion_ranking);
				else
					protocol::SerializeType(pBuffer, &list_profesion_ranking);
			}
			protocol::SerializeType(pBuffer, &flag_list_achieve);
			if (true == flag_list_achieve)
			{
				if (nullptr != p_list_achieve)
					protocol::SerializeType(pBuffer, p_list_achieve);
				else
					protocol::SerializeType(pBuffer, &list_achieve);
			}
			protocol::SerializeType(pBuffer, &pet_team);
			protocol::SerializeType(pBuffer, &flag_list_challenge);
			if (true == flag_list_challenge)
			{
				if (nullptr != p_list_challenge)
					protocol::SerializeType(pBuffer, p_list_challenge);
				else
					protocol::SerializeType(pBuffer, &list_challenge);
			}
			protocol::SerializeType(pBuffer, &cumulative_connection_time);
			protocol::SerializeType(pBuffer, &worship_info);
			protocol::SerializeType(pBuffer, &flag_illusion_dungeon);
			if (true == flag_illusion_dungeon)
			{
				if (nullptr != p_illusion_dungeon)
					protocol::SerializeType(pBuffer, p_illusion_dungeon);
				else
					protocol::SerializeType(pBuffer, &illusion_dungeon);
			}
			protocol::SerializeType(pBuffer, &field_boss_kill_count);
			protocol::SerializeType(pBuffer, &arena_join_count);
			protocol::SerializeType(pBuffer, &exp);
			protocol::SerializeType(pBuffer, &expert_exp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
