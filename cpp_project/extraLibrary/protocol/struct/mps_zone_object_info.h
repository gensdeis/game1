#pragma once
#include <vector>
#include <string>
#include "mps_vector.h"
#include "mps_zone_player_info.h"
#include "mps_zone_monster_info.h"
#include "mps_zone_drop_item_info.h"
#include "mps_zone_collect_info.h"
#include "mps_zone_character_minion.h"
#include "mps_zone_npc_info.h"
#include "mps_zone_siege_weapon_info.h"
#include "mps_zone_fixed_object_info.h"
#include "mps_zone_mercenary_info.h"
#include "mps_zone_treasure_box_info.h"
#include "mps_zone_player_avatar_info.h"
#include "mps_lord_statue_info.h"
#include "mps_seal_device_info.h"
#include "mps_street_stall_object_info.h"

namespace mir3d
{
	class mps_zone_object_info 
	{
	public:
		int64_t uuid{};	// uid
	public:
		int32_t type{};	// type
	public:
		int32_t id{};	// tableid
	private:
		bool flag_pos = false;
		mps_vector pos;
		mps_vector* p_pos = nullptr;
	public:
		bool has_pos() const
		{
			return flag_pos;
		}
		mps_vector* alloc_pos()
		{
			flag_pos = true;
			return &pos;
		}
		const mps_vector* get_pos() const
		{
			if (true == flag_pos)
			{
				if (nullptr == p_pos)
				{
					return &pos;
				}
				return p_pos;
			}
			return nullptr;
		}
		void set_pos(mps_vector* in_pos)
		{
			if (nullptr == p_pos)
			{
				p_pos = in_pos;
				flag_pos = true;
			}
		}
	private:
		bool flag_player_info = false;
		mps_zone_player_info player_info;
		mps_zone_player_info* p_player_info = nullptr;
	public:
		bool has_player_info() const
		{
			return flag_player_info;
		}
		mps_zone_player_info* alloc_player_info()
		{
			flag_player_info = true;
			return &player_info;
		}
		const mps_zone_player_info* get_player_info() const
		{
			if (true == flag_player_info)
			{
				if (nullptr == p_player_info)
				{
					return &player_info;
				}
				return p_player_info;
			}
			return nullptr;
		}
		void set_player_info(mps_zone_player_info* in_player_info)
		{
			if (nullptr == p_player_info)
			{
				p_player_info = in_player_info;
				flag_player_info = true;
			}
		}
	private:
		bool flag_monster_info = false;
		mps_zone_monster_info monster_info;
		mps_zone_monster_info* p_monster_info = nullptr;
	public:
		bool has_monster_info() const
		{
			return flag_monster_info;
		}
		mps_zone_monster_info* alloc_monster_info()
		{
			flag_monster_info = true;
			return &monster_info;
		}
		const mps_zone_monster_info* get_monster_info() const
		{
			if (true == flag_monster_info)
			{
				if (nullptr == p_monster_info)
				{
					return &monster_info;
				}
				return p_monster_info;
			}
			return nullptr;
		}
		void set_monster_info(mps_zone_monster_info* in_monster_info)
		{
			if (nullptr == p_monster_info)
			{
				p_monster_info = in_monster_info;
				flag_monster_info = true;
			}
		}
	private:
		bool flag_drop_info = false;
		mps_zone_drop_item_info drop_info;
		mps_zone_drop_item_info* p_drop_info = nullptr;
	public:
		bool has_drop_info() const
		{
			return flag_drop_info;
		}
		mps_zone_drop_item_info* alloc_drop_info()
		{
			flag_drop_info = true;
			return &drop_info;
		}
		const mps_zone_drop_item_info* get_drop_info() const
		{
			if (true == flag_drop_info)
			{
				if (nullptr == p_drop_info)
				{
					return &drop_info;
				}
				return p_drop_info;
			}
			return nullptr;
		}
		void set_drop_info(mps_zone_drop_item_info* in_drop_info)
		{
			if (nullptr == p_drop_info)
			{
				p_drop_info = in_drop_info;
				flag_drop_info = true;
			}
		}
	private:
		bool flag_collect_info = false;
		mps_zone_collect_info collect_info;
		mps_zone_collect_info* p_collect_info = nullptr;
	public:
		bool has_collect_info() const
		{
			return flag_collect_info;
		}
		mps_zone_collect_info* alloc_collect_info()
		{
			flag_collect_info = true;
			return &collect_info;
		}
		const mps_zone_collect_info* get_collect_info() const
		{
			if (true == flag_collect_info)
			{
				if (nullptr == p_collect_info)
				{
					return &collect_info;
				}
				return p_collect_info;
			}
			return nullptr;
		}
		void set_collect_info(mps_zone_collect_info* in_collect_info)
		{
			if (nullptr == p_collect_info)
			{
				p_collect_info = in_collect_info;
				flag_collect_info = true;
			}
		}
	private:
		bool flag_minion_info = false;
		mps_zone_character_minion minion_info;
		mps_zone_character_minion* p_minion_info = nullptr;
	public:
		bool has_minion_info() const
		{
			return flag_minion_info;
		}
		mps_zone_character_minion* alloc_minion_info()
		{
			flag_minion_info = true;
			return &minion_info;
		}
		const mps_zone_character_minion* get_minion_info() const
		{
			if (true == flag_minion_info)
			{
				if (nullptr == p_minion_info)
				{
					return &minion_info;
				}
				return p_minion_info;
			}
			return nullptr;
		}
		void set_minion_info(mps_zone_character_minion* in_minion_info)
		{
			if (nullptr == p_minion_info)
			{
				p_minion_info = in_minion_info;
				flag_minion_info = true;
			}
		}
	public:
		int32_t angle{};
	private:
		bool flag_npc_info = false;
		mps_zone_npc_info npc_info;
		mps_zone_npc_info* p_npc_info = nullptr;
	public:
		bool has_npc_info() const
		{
			return flag_npc_info;
		}
		mps_zone_npc_info* alloc_npc_info()
		{
			flag_npc_info = true;
			return &npc_info;
		}
		const mps_zone_npc_info* get_npc_info() const
		{
			if (true == flag_npc_info)
			{
				if (nullptr == p_npc_info)
				{
					return &npc_info;
				}
				return p_npc_info;
			}
			return nullptr;
		}
		void set_npc_info(mps_zone_npc_info* in_npc_info)
		{
			if (nullptr == p_npc_info)
			{
				p_npc_info = in_npc_info;
				flag_npc_info = true;
			}
		}
	private:
		bool flag_siege_weapon_info = false;
		mps_zone_siege_weapon_info siege_weapon_info;
		mps_zone_siege_weapon_info* p_siege_weapon_info = nullptr;
	public:
		bool has_siege_weapon_info() const
		{
			return flag_siege_weapon_info;
		}
		mps_zone_siege_weapon_info* alloc_siege_weapon_info()
		{
			flag_siege_weapon_info = true;
			return &siege_weapon_info;
		}
		const mps_zone_siege_weapon_info* get_siege_weapon_info() const
		{
			if (true == flag_siege_weapon_info)
			{
				if (nullptr == p_siege_weapon_info)
				{
					return &siege_weapon_info;
				}
				return p_siege_weapon_info;
			}
			return nullptr;
		}
		void set_siege_weapon_info(mps_zone_siege_weapon_info* in_siege_weapon_info)
		{
			if (nullptr == p_siege_weapon_info)
			{
				p_siege_weapon_info = in_siege_weapon_info;
				flag_siege_weapon_info = true;
			}
		}
	private:
		bool flag_fixed_object_info = false;
		mps_zone_fixed_object_info fixed_object_info;
		mps_zone_fixed_object_info* p_fixed_object_info = nullptr;
	public:
		bool has_fixed_object_info() const
		{
			return flag_fixed_object_info;
		}
		mps_zone_fixed_object_info* alloc_fixed_object_info()
		{
			flag_fixed_object_info = true;
			return &fixed_object_info;
		}
		const mps_zone_fixed_object_info* get_fixed_object_info() const
		{
			if (true == flag_fixed_object_info)
			{
				if (nullptr == p_fixed_object_info)
				{
					return &fixed_object_info;
				}
				return p_fixed_object_info;
			}
			return nullptr;
		}
		void set_fixed_object_info(mps_zone_fixed_object_info* in_fixed_object_info)
		{
			if (nullptr == p_fixed_object_info)
			{
				p_fixed_object_info = in_fixed_object_info;
				flag_fixed_object_info = true;
			}
		}
	private:
		bool flag_mercenary_info = false;
		mps_zone_mercenary_info mercenary_info;
		mps_zone_mercenary_info* p_mercenary_info = nullptr;
	public:
		bool has_mercenary_info() const
		{
			return flag_mercenary_info;
		}
		mps_zone_mercenary_info* alloc_mercenary_info()
		{
			flag_mercenary_info = true;
			return &mercenary_info;
		}
		const mps_zone_mercenary_info* get_mercenary_info() const
		{
			if (true == flag_mercenary_info)
			{
				if (nullptr == p_mercenary_info)
				{
					return &mercenary_info;
				}
				return p_mercenary_info;
			}
			return nullptr;
		}
		void set_mercenary_info(mps_zone_mercenary_info* in_mercenary_info)
		{
			if (nullptr == p_mercenary_info)
			{
				p_mercenary_info = in_mercenary_info;
				flag_mercenary_info = true;
			}
		}
	public:
		uint8_t team_index{};
	private:
		bool flag_treasure_box_info = false;
		mps_zone_treasure_box_info treasure_box_info;	// 필드 보물 상자 정보
		mps_zone_treasure_box_info* p_treasure_box_info = nullptr;
	public:
		bool has_treasure_box_info() const
		{
			return flag_treasure_box_info;
		}
		mps_zone_treasure_box_info* alloc_treasure_box_info()
		{
			flag_treasure_box_info = true;
			return &treasure_box_info;
		}
		const mps_zone_treasure_box_info* get_treasure_box_info() const
		{
			if (true == flag_treasure_box_info)
			{
				if (nullptr == p_treasure_box_info)
				{
					return &treasure_box_info;
				}
				return p_treasure_box_info;
			}
			return nullptr;
		}
		void set_treasure_box_info(mps_zone_treasure_box_info* in_treasure_box_info)
		{
			if (nullptr == p_treasure_box_info)
			{
				p_treasure_box_info = in_treasure_box_info;
				flag_treasure_box_info = true;
			}
		}
	private:
		bool flag_avatar_info = false;
		mps_zone_player_avatar_info avatar_info;	// 캐릭터가 변신한 아바타 정보
		mps_zone_player_avatar_info* p_avatar_info = nullptr;
	public:
		bool has_avatar_info() const
		{
			return flag_avatar_info;
		}
		mps_zone_player_avatar_info* alloc_avatar_info()
		{
			flag_avatar_info = true;
			return &avatar_info;
		}
		const mps_zone_player_avatar_info* get_avatar_info() const
		{
			if (true == flag_avatar_info)
			{
				if (nullptr == p_avatar_info)
				{
					return &avatar_info;
				}
				return p_avatar_info;
			}
			return nullptr;
		}
		void set_avatar_info(mps_zone_player_avatar_info* in_avatar_info)
		{
			if (nullptr == p_avatar_info)
			{
				p_avatar_info = in_avatar_info;
				flag_avatar_info = true;
			}
		}
	private:
		bool flag_lord_statue_info = false;
		mps_lord_statue_info lord_statue_info;	// 동상 정보
		mps_lord_statue_info* p_lord_statue_info = nullptr;
	public:
		bool has_lord_statue_info() const
		{
			return flag_lord_statue_info;
		}
		mps_lord_statue_info* alloc_lord_statue_info()
		{
			flag_lord_statue_info = true;
			return &lord_statue_info;
		}
		const mps_lord_statue_info* get_lord_statue_info() const
		{
			if (true == flag_lord_statue_info)
			{
				if (nullptr == p_lord_statue_info)
				{
					return &lord_statue_info;
				}
				return p_lord_statue_info;
			}
			return nullptr;
		}
		void set_lord_statue_info(mps_lord_statue_info* in_lord_statue_info)
		{
			if (nullptr == p_lord_statue_info)
			{
				p_lord_statue_info = in_lord_statue_info;
				flag_lord_statue_info = true;
			}
		}
	private:
		bool flag_seal_device_info = false;
		mps_seal_device_info seal_device_info;	// 봉인장치 정보
		mps_seal_device_info* p_seal_device_info = nullptr;
	public:
		bool has_seal_device_info() const
		{
			return flag_seal_device_info;
		}
		mps_seal_device_info* alloc_seal_device_info()
		{
			flag_seal_device_info = true;
			return &seal_device_info;
		}
		const mps_seal_device_info* get_seal_device_info() const
		{
			if (true == flag_seal_device_info)
			{
				if (nullptr == p_seal_device_info)
				{
					return &seal_device_info;
				}
				return p_seal_device_info;
			}
			return nullptr;
		}
		void set_seal_device_info(mps_seal_device_info* in_seal_device_info)
		{
			if (nullptr == p_seal_device_info)
			{
				p_seal_device_info = in_seal_device_info;
				flag_seal_device_info = true;
			}
		}
	private:
		bool flag_street_stall_info = false;
		mps_street_stall_object_info street_stall_info;	// 개인노점 정보
		mps_street_stall_object_info* p_street_stall_info = nullptr;
	public:
		bool has_street_stall_info() const
		{
			return flag_street_stall_info;
		}
		mps_street_stall_object_info* alloc_street_stall_info()
		{
			flag_street_stall_info = true;
			return &street_stall_info;
		}
		const mps_street_stall_object_info* get_street_stall_info() const
		{
			if (true == flag_street_stall_info)
			{
				if (nullptr == p_street_stall_info)
				{
					return &street_stall_info;
				}
				return p_street_stall_info;
			}
			return nullptr;
		}
		void set_street_stall_info(mps_street_stall_object_info* in_street_stall_info)
		{
			if (nullptr == p_street_stall_info)
			{
				p_street_stall_info = in_street_stall_info;
				flag_street_stall_info = true;
			}
		}

	public:
		mps_zone_object_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &uuid);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &flag_pos);
			if (true == flag_pos)
			{
				if (nullptr != p_pos)
					protocol::SerializeType(pBuffer, p_pos);
				else
					protocol::SerializeType(pBuffer, &pos);
			}
			protocol::SerializeType(pBuffer, &flag_player_info);
			if (true == flag_player_info)
			{
				if (nullptr != p_player_info)
					protocol::SerializeType(pBuffer, p_player_info);
				else
					protocol::SerializeType(pBuffer, &player_info);
			}
			protocol::SerializeType(pBuffer, &flag_monster_info);
			if (true == flag_monster_info)
			{
				if (nullptr != p_monster_info)
					protocol::SerializeType(pBuffer, p_monster_info);
				else
					protocol::SerializeType(pBuffer, &monster_info);
			}
			protocol::SerializeType(pBuffer, &flag_drop_info);
			if (true == flag_drop_info)
			{
				if (nullptr != p_drop_info)
					protocol::SerializeType(pBuffer, p_drop_info);
				else
					protocol::SerializeType(pBuffer, &drop_info);
			}
			protocol::SerializeType(pBuffer, &flag_collect_info);
			if (true == flag_collect_info)
			{
				if (nullptr != p_collect_info)
					protocol::SerializeType(pBuffer, p_collect_info);
				else
					protocol::SerializeType(pBuffer, &collect_info);
			}
			protocol::SerializeType(pBuffer, &flag_minion_info);
			if (true == flag_minion_info)
			{
				if (nullptr != p_minion_info)
					protocol::SerializeType(pBuffer, p_minion_info);
				else
					protocol::SerializeType(pBuffer, &minion_info);
			}
			protocol::SerializeType(pBuffer, &angle);
			protocol::SerializeType(pBuffer, &flag_npc_info);
			if (true == flag_npc_info)
			{
				if (nullptr != p_npc_info)
					protocol::SerializeType(pBuffer, p_npc_info);
				else
					protocol::SerializeType(pBuffer, &npc_info);
			}
			protocol::SerializeType(pBuffer, &flag_siege_weapon_info);
			if (true == flag_siege_weapon_info)
			{
				if (nullptr != p_siege_weapon_info)
					protocol::SerializeType(pBuffer, p_siege_weapon_info);
				else
					protocol::SerializeType(pBuffer, &siege_weapon_info);
			}
			protocol::SerializeType(pBuffer, &flag_fixed_object_info);
			if (true == flag_fixed_object_info)
			{
				if (nullptr != p_fixed_object_info)
					protocol::SerializeType(pBuffer, p_fixed_object_info);
				else
					protocol::SerializeType(pBuffer, &fixed_object_info);
			}
			protocol::SerializeType(pBuffer, &flag_mercenary_info);
			if (true == flag_mercenary_info)
			{
				if (nullptr != p_mercenary_info)
					protocol::SerializeType(pBuffer, p_mercenary_info);
				else
					protocol::SerializeType(pBuffer, &mercenary_info);
			}
			protocol::SerializeType(pBuffer, &team_index);
			protocol::SerializeType(pBuffer, &flag_treasure_box_info);
			if (true == flag_treasure_box_info)
			{
				if (nullptr != p_treasure_box_info)
					protocol::SerializeType(pBuffer, p_treasure_box_info);
				else
					protocol::SerializeType(pBuffer, &treasure_box_info);
			}
			protocol::SerializeType(pBuffer, &flag_avatar_info);
			if (true == flag_avatar_info)
			{
				if (nullptr != p_avatar_info)
					protocol::SerializeType(pBuffer, p_avatar_info);
				else
					protocol::SerializeType(pBuffer, &avatar_info);
			}
			protocol::SerializeType(pBuffer, &flag_lord_statue_info);
			if (true == flag_lord_statue_info)
			{
				if (nullptr != p_lord_statue_info)
					protocol::SerializeType(pBuffer, p_lord_statue_info);
				else
					protocol::SerializeType(pBuffer, &lord_statue_info);
			}
			protocol::SerializeType(pBuffer, &flag_seal_device_info);
			if (true == flag_seal_device_info)
			{
				if (nullptr != p_seal_device_info)
					protocol::SerializeType(pBuffer, p_seal_device_info);
				else
					protocol::SerializeType(pBuffer, &seal_device_info);
			}
			protocol::SerializeType(pBuffer, &flag_street_stall_info);
			if (true == flag_street_stall_info)
			{
				if (nullptr != p_street_stall_info)
					protocol::SerializeType(pBuffer, p_street_stall_info);
				else
					protocol::SerializeType(pBuffer, &street_stall_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
