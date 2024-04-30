#pragma once
#include <vector>
#include <string>
#include "mps_guild_dungeon_member_damage.h"

namespace mir3d
{
	class mps_guild_dungeon_member_damage_info 
	{
	public:
		int32_t tid{};	// 던전tid
	public:
		int32_t kill_monster_count{};	// 죽은몬스터수
	public:
		int32_t total_monster_hp{};	// 몬스터의총hp
	public:
		std::vector<mps_guild_dungeon_member_damage> list{};	// 유저피해량목록

	public:
		mps_guild_dungeon_member_damage_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &kill_monster_count);
			protocol::SerializeType(pBuffer, &total_monster_hp);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
