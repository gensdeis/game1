#pragma once
#include <vector>
#include <string>
#include "mps_guild_master_order_quest.h"
#include "mps_guild_castle_info.h"
#include "mps_guild_town_info.h"
#include "mps_guild_dungeon_info.h"
#include "mps_ranking_history.h"
#include "mps_guild_league_info.h"
#include "mps_guild_ally_simple_info.h"

namespace mir3d
{
	class mps_guild 
	{
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		mpe_guild_join_type join_type{};
	public:
		int32_t join_level{};
	public:
		int64_t master_cuid{};
	public:
		int32_t gold{};
	public:
		std::string introduction{};
	public:
		std::string notice{};
	public:
		int32_t level{};
	public:
		int32_t exp{};
	public:
		int32_t current_member_count{};
	public:
		int32_t max_member_count{};
	public:
		int32_t current_elder_count{};
	public:
		int32_t max_elder_count{};
	public:
		int64_t create_time{};
	public:
		int64_t member_contribution_weekly_point_reset_time{};
	public:
		std::string master_nickname{};
	public:
		int32_t storage_share_slot_count{};
	private:
		bool flag_master_order_quest = false;
		mps_guild_master_order_quest master_order_quest;
		mps_guild_master_order_quest* p_master_order_quest = nullptr;
	public:
		bool has_master_order_quest() const
		{
			return flag_master_order_quest;
		}
		mps_guild_master_order_quest* alloc_master_order_quest()
		{
			flag_master_order_quest = true;
			return &master_order_quest;
		}
		const mps_guild_master_order_quest* get_master_order_quest() const
		{
			if (true == flag_master_order_quest)
			{
				if (nullptr == p_master_order_quest)
				{
					return &master_order_quest;
				}
				return p_master_order_quest;
			}
			return nullptr;
		}
		void set_master_order_quest(mps_guild_master_order_quest* in_master_order_quest)
		{
			if (nullptr == p_master_order_quest)
			{
				p_master_order_quest = in_master_order_quest;
				flag_master_order_quest = true;
			}
		}
	public:
		std::vector<mps_guild_castle_info> castle_info{};	// 성주길드정보
	private:
		bool flag_town_info = false;
		mps_guild_town_info town_info;	// 장원 정보
		mps_guild_town_info* p_town_info = nullptr;
	public:
		bool has_town_info() const
		{
			return flag_town_info;
		}
		mps_guild_town_info* alloc_town_info()
		{
			flag_town_info = true;
			return &town_info;
		}
		const mps_guild_town_info* get_town_info() const
		{
			if (true == flag_town_info)
			{
				if (nullptr == p_town_info)
				{
					return &town_info;
				}
				return p_town_info;
			}
			return nullptr;
		}
		void set_town_info(mps_guild_town_info* in_town_info)
		{
			if (nullptr == p_town_info)
			{
				p_town_info = in_town_info;
				flag_town_info = true;
			}
		}
	private:
		bool flag_dungeon_info = false;
		mps_guild_dungeon_info dungeon_info;	// 던전 정보
		mps_guild_dungeon_info* p_dungeon_info = nullptr;
	public:
		bool has_dungeon_info() const
		{
			return flag_dungeon_info;
		}
		mps_guild_dungeon_info* alloc_dungeon_info()
		{
			flag_dungeon_info = true;
			return &dungeon_info;
		}
		const mps_guild_dungeon_info* get_dungeon_info() const
		{
			if (true == flag_dungeon_info)
			{
				if (nullptr == p_dungeon_info)
				{
					return &dungeon_info;
				}
				return p_dungeon_info;
			}
			return nullptr;
		}
		void set_dungeon_info(mps_guild_dungeon_info* in_dungeon_info)
		{
			if (nullptr == p_dungeon_info)
			{
				p_dungeon_info = in_dungeon_info;
				flag_dungeon_info = true;
			}
		}
	private:
		bool flag_ranking = false;
		mps_ranking_history ranking;	// 길드 랭킹정보
		mps_ranking_history* p_ranking = nullptr;
	public:
		bool has_ranking() const
		{
			return flag_ranking;
		}
		mps_ranking_history* alloc_ranking()
		{
			flag_ranking = true;
			return &ranking;
		}
		const mps_ranking_history* get_ranking() const
		{
			if (true == flag_ranking)
			{
				if (nullptr == p_ranking)
				{
					return &ranking;
				}
				return p_ranking;
			}
			return nullptr;
		}
		void set_ranking(mps_ranking_history* in_ranking)
		{
			if (nullptr == p_ranking)
			{
				p_ranking = in_ranking;
				flag_ranking = true;
			}
		}
	public:
		int32_t pr_count{};
	public:
		int64_t pr_count_reset_time{};
	public:
		mpe_guild_type guild_type{};	// 문파 타입
	private:
		bool flag_league_info = false;
		mps_guild_league_info league_info;	// 리그정보
		mps_guild_league_info* p_league_info = nullptr;
	public:
		bool has_league_info() const
		{
			return flag_league_info;
		}
		mps_guild_league_info* alloc_league_info()
		{
			flag_league_info = true;
			return &league_info;
		}
		const mps_guild_league_info* get_league_info() const
		{
			if (true == flag_league_info)
			{
				if (nullptr == p_league_info)
				{
					return &league_info;
				}
				return p_league_info;
			}
			return nullptr;
		}
		void set_league_info(mps_guild_league_info* in_league_info)
		{
			if (nullptr == p_league_info)
			{
				p_league_info = in_league_info;
				flag_league_info = true;
			}
		}
	public:
		std::vector<uint8_t> guild_mark{};	// 문파 문양
	public:
		int32_t blackiron{};	// 흑철
	public:
		int32_t goldingot{};
	public:
		int64_t notice_update_time{};
	public:
		std::vector<mps_guild_ally_simple_info> ally_guid_list{};	// "동맹 문파 UID 목록"
	public:
		int32_t guild_power{};	// "길드전투력 (문원전투력합)"

	public:
		mps_guild()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeEnum(pBuffer, &join_type);
			protocol::SerializeType(pBuffer, &join_level);
			protocol::SerializeType(pBuffer, &master_cuid);
			protocol::SerializeType(pBuffer, &gold);
			protocol::SerializeType(pBuffer, &introduction);
			protocol::SerializeType(pBuffer, &notice);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &exp);
			protocol::SerializeType(pBuffer, &current_member_count);
			protocol::SerializeType(pBuffer, &max_member_count);
			protocol::SerializeType(pBuffer, &current_elder_count);
			protocol::SerializeType(pBuffer, &max_elder_count);
			protocol::SerializeType(pBuffer, &create_time);
			protocol::SerializeType(pBuffer, &member_contribution_weekly_point_reset_time);
			protocol::SerializeType(pBuffer, &master_nickname);
			protocol::SerializeType(pBuffer, &storage_share_slot_count);
			protocol::SerializeType(pBuffer, &flag_master_order_quest);
			if (true == flag_master_order_quest)
			{
				if (nullptr != p_master_order_quest)
					protocol::SerializeType(pBuffer, p_master_order_quest);
				else
					protocol::SerializeType(pBuffer, &master_order_quest);
			}
			protocol::SerializeType(pBuffer, &castle_info);
			protocol::SerializeType(pBuffer, &flag_town_info);
			if (true == flag_town_info)
			{
				if (nullptr != p_town_info)
					protocol::SerializeType(pBuffer, p_town_info);
				else
					protocol::SerializeType(pBuffer, &town_info);
			}
			protocol::SerializeType(pBuffer, &flag_dungeon_info);
			if (true == flag_dungeon_info)
			{
				if (nullptr != p_dungeon_info)
					protocol::SerializeType(pBuffer, p_dungeon_info);
				else
					protocol::SerializeType(pBuffer, &dungeon_info);
			}
			protocol::SerializeType(pBuffer, &flag_ranking);
			if (true == flag_ranking)
			{
				if (nullptr != p_ranking)
					protocol::SerializeType(pBuffer, p_ranking);
				else
					protocol::SerializeType(pBuffer, &ranking);
			}
			protocol::SerializeType(pBuffer, &pr_count);
			protocol::SerializeType(pBuffer, &pr_count_reset_time);
			protocol::SerializeEnum(pBuffer, &guild_type);
			protocol::SerializeType(pBuffer, &flag_league_info);
			if (true == flag_league_info)
			{
				if (nullptr != p_league_info)
					protocol::SerializeType(pBuffer, p_league_info);
				else
					protocol::SerializeType(pBuffer, &league_info);
			}
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &blackiron);
			protocol::SerializeType(pBuffer, &goldingot);
			protocol::SerializeType(pBuffer, &notice_update_time);
			protocol::SerializeType(pBuffer, &ally_guid_list);
			protocol::SerializeType(pBuffer, &guild_power);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
