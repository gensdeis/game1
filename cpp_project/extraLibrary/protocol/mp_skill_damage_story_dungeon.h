#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_skill_damage_story_dungeon_cs : public BasePacket 	// 스토리 던전 스킬 데미지용
	{
	public:
		int64_t owner_uid {};
	public:
		int32_t skill_id{};	// 스킬 id
	public:
		int64_t skill_uid{};	// 클라기반 skill uid
	public:
		mpe_direction skill_dir{};	// 스킬 방향
	public:
		std::vector<int64_t> target_uid_list{};	// 타겟 uid list

	public:
		mp_skill_damage_story_dungeon_cs() : BasePacket(mpe_cmd::skill_damage_story_dungeon_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &owner_uid );
			protocol::SerializeType(pBuffer, &skill_id);
			protocol::SerializeType(pBuffer, &skill_uid);
			protocol::SerializeEnum(pBuffer, &skill_dir);
			protocol::SerializeType(pBuffer, &target_uid_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_skill_damage_story_dungeon_sc : public BasePacket 	// 스토리 던전 스킬 데미지용
	{

	public:
		mp_skill_damage_story_dungeon_sc() : BasePacket(mpe_cmd::skill_damage_story_dungeon_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
