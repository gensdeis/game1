#pragma once
#include <vector>
#include <string>
#include "mps_item_add.h"
#include "mps_item.h"
#include "mrpcs_item_stone_pair.h"
#include "mps_siege_machine.h"
#include "mps_guild_dungeon_info.h"
#include "mrpcs_guild_dungeon_reward.h"
#include "mps_character_situation.h"
#include "mps_vector.h"
#include "mps_other_guild_info.h"

namespace mir3d
{
	class mrpcs_guild_context 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		mpe_guild_join_type join_type{};
	public:
		int32_t join_level{};
	public:
		int64_t target_uid{};
	public:
		std::string target_guild_name{};
	public:
		std::string name{};
	public:
		std::string message{};
	public:
		bool accept{};
	public:
		int32_t guild_gold{};
	public:
		int32_t negotiation_gold{};
	public:
		int64_t negotiation_expire_time{};
	public:
		std::string introdution{};
	public:
		std::string notice{};
	public:
		mpe_guild_member_grade grade{};
	public:
		mpe_guild_donation_type donation_type{};
	private:
		bool flag_use_item_info = false;
		mps_item_add use_item_info;
		mps_item_add* p_use_item_info = nullptr;
	public:
		bool has_use_item_info() const
		{
			return flag_use_item_info;
		}
		mps_item_add* alloc_use_item_info()
		{
			flag_use_item_info = true;
			return &use_item_info;
		}
		const mps_item_add* get_use_item_info() const
		{
			if (true == flag_use_item_info)
			{
				if (nullptr == p_use_item_info)
				{
					return &use_item_info;
				}
				return p_use_item_info;
			}
			return nullptr;
		}
		void set_use_item_info(mps_item_add* in_use_item_info)
		{
			if (nullptr == p_use_item_info)
			{
				p_use_item_info = in_use_item_info;
				flag_use_item_info = true;
			}
		}
	private:
		bool flag_request_item_in_storage = false;
		mps_item request_item_in_storage;
		mps_item* p_request_item_in_storage = nullptr;
	public:
		bool has_request_item_in_storage() const
		{
			return flag_request_item_in_storage;
		}
		mps_item* alloc_request_item_in_storage()
		{
			flag_request_item_in_storage = true;
			return &request_item_in_storage;
		}
		const mps_item* get_request_item_in_storage() const
		{
			if (true == flag_request_item_in_storage)
			{
				if (nullptr == p_request_item_in_storage)
				{
					return &request_item_in_storage;
				}
				return p_request_item_in_storage;
			}
			return nullptr;
		}
		void set_request_item_in_storage(mps_item* in_request_item_in_storage)
		{
			if (nullptr == p_request_item_in_storage)
			{
				p_request_item_in_storage = in_request_item_in_storage;
				flag_request_item_in_storage = true;
			}
		}
	public:
		std::vector<mrpcs_item_stone_pair> list_enchant_stone{};
	public:
		int32_t skill_id{};
	public:
		int32_t reject_count{};
	public:
		int64_t next_available_start_time{};
	public:
		mrpce_guild_request_type request_type{};
	public:
		mpe_siege_castle_type castle_type{};	// 성타입
	public:
		int32_t common_value{};	// "입찰금액 등 공성,성관리 공용사용"
	public:
		int32_t common_value_2{};	// 공용사용2
	public:
		std::vector<mps_siege_machine> machine_info{};	// 공성무기정보
	public:
		bool online{};
	public:
		int64_t last_online_time{};
	public:
		bool in_siege_map{};
	public:
		int32_t reward_exp{};
	public:
		mrpce_guild_add_exp_type add_exp_type{};
	public:
		mpe_castle_town_work_type work_type{};	// 장원 작업 타입
	public:
		int32_t extend_slot_count{};
	private:
		bool flag_dungeon_info = false;
		mps_guild_dungeon_info dungeon_info;
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
	public:
		std::vector<int32_t> list_reward_tid{};
	public:
		bool common_bool_value{};
	public:
		int32_t dungeon_monster_total_hp{};	// 몬스터총hp
	public:
		int32_t dungeon_damage{};
	public:
		int32_t dungeon_kill_monster_count{};
	public:
		std::vector<mrpcs_guild_dungeon_reward> dungeon_reward{};
	public:
		mpe_guild_type guild_type{};
	public:
		std::vector<mps_character_situation> list_situation{};
	public:
		uint8_t tag_{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		mrpce_guild_reset_type reset_type{};
	public:
		int32_t gid{};
	public:
		int32_t expert_level{};	// 전직 레벨
	private:
		bool flag_position = false;
		mps_vector position;	// "위치정보"
		mps_vector* p_position = nullptr;
	public:
		bool has_position() const
		{
			return flag_position;
		}
		mps_vector* alloc_position()
		{
			flag_position = true;
			return &position;
		}
		const mps_vector* get_position() const
		{
			if (true == flag_position)
			{
				if (nullptr == p_position)
				{
					return &position;
				}
				return p_position;
			}
			return nullptr;
		}
		void set_position(mps_vector* in_position)
		{
			if (nullptr == p_position)
			{
				p_position = in_position;
				flag_position = true;
			}
		}
	private:
		bool flag_other_guild = false;
		mps_other_guild_info other_guild;	// "타 길드정보"
		mps_other_guild_info* p_other_guild = nullptr;
	public:
		bool has_other_guild() const
		{
			return flag_other_guild;
		}
		mps_other_guild_info* alloc_other_guild()
		{
			flag_other_guild = true;
			return &other_guild;
		}
		const mps_other_guild_info* get_other_guild() const
		{
			if (true == flag_other_guild)
			{
				if (nullptr == p_other_guild)
				{
					return &other_guild;
				}
				return p_other_guild;
			}
			return nullptr;
		}
		void set_other_guild(mps_other_guild_info* in_other_guild)
		{
			if (nullptr == p_other_guild)
			{
				p_other_guild = in_other_guild;
				flag_other_guild = true;
			}
		}

	public:
		mrpcs_guild_context()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeEnum(pBuffer, &join_type);
			protocol::SerializeType(pBuffer, &join_level);
			protocol::SerializeType(pBuffer, &target_uid);
			protocol::SerializeType(pBuffer, &target_guild_name);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &message);
			protocol::SerializeType(pBuffer, &accept);
			protocol::SerializeType(pBuffer, &guild_gold);
			protocol::SerializeType(pBuffer, &negotiation_gold);
			protocol::SerializeType(pBuffer, &negotiation_expire_time);
			protocol::SerializeType(pBuffer, &introdution);
			protocol::SerializeType(pBuffer, &notice);
			protocol::SerializeEnum(pBuffer, &grade);
			protocol::SerializeEnum(pBuffer, &donation_type);
			protocol::SerializeType(pBuffer, &flag_use_item_info);
			if (true == flag_use_item_info)
			{
				if (nullptr != p_use_item_info)
					protocol::SerializeType(pBuffer, p_use_item_info);
				else
					protocol::SerializeType(pBuffer, &use_item_info);
			}
			protocol::SerializeType(pBuffer, &flag_request_item_in_storage);
			if (true == flag_request_item_in_storage)
			{
				if (nullptr != p_request_item_in_storage)
					protocol::SerializeType(pBuffer, p_request_item_in_storage);
				else
					protocol::SerializeType(pBuffer, &request_item_in_storage);
			}
			protocol::SerializeType(pBuffer, &list_enchant_stone);
			protocol::SerializeType(pBuffer, &skill_id);
			protocol::SerializeType(pBuffer, &reject_count);
			protocol::SerializeType(pBuffer, &next_available_start_time);
			protocol::SerializeEnum(pBuffer, &request_type);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &common_value);
			protocol::SerializeType(pBuffer, &common_value_2);
			protocol::SerializeType(pBuffer, &machine_info);
			protocol::SerializeType(pBuffer, &online);
			protocol::SerializeType(pBuffer, &last_online_time);
			protocol::SerializeType(pBuffer, &in_siege_map);
			protocol::SerializeType(pBuffer, &reward_exp);
			protocol::SerializeEnum(pBuffer, &add_exp_type);
			protocol::SerializeEnum(pBuffer, &work_type);
			protocol::SerializeType(pBuffer, &extend_slot_count);
			protocol::SerializeType(pBuffer, &flag_dungeon_info);
			if (true == flag_dungeon_info)
			{
				if (nullptr != p_dungeon_info)
					protocol::SerializeType(pBuffer, p_dungeon_info);
				else
					protocol::SerializeType(pBuffer, &dungeon_info);
			}
			protocol::SerializeType(pBuffer, &list_reward_tid);
			protocol::SerializeType(pBuffer, &common_bool_value);
			protocol::SerializeType(pBuffer, &dungeon_monster_total_hp);
			protocol::SerializeType(pBuffer, &dungeon_damage);
			protocol::SerializeType(pBuffer, &dungeon_kill_monster_count);
			protocol::SerializeType(pBuffer, &dungeon_reward);
			protocol::SerializeEnum(pBuffer, &guild_type);
			protocol::SerializeType(pBuffer, &list_situation);
			protocol::SerializeType(pBuffer, &tag_);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeEnum(pBuffer, &reset_type);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &expert_level);
			protocol::SerializeType(pBuffer, &flag_position);
			if (true == flag_position)
			{
				if (nullptr != p_position)
					protocol::SerializeType(pBuffer, p_position);
				else
					protocol::SerializeType(pBuffer, &position);
			}
			protocol::SerializeType(pBuffer, &flag_other_guild);
			if (true == flag_other_guild)
			{
				if (nullptr != p_other_guild)
					protocol::SerializeType(pBuffer, p_other_guild);
				else
					protocol::SerializeType(pBuffer, &other_guild);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
