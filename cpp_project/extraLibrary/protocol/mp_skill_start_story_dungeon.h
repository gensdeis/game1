#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_buff.h"

namespace mir3d
{
	class mp_skill_start_story_dungeon_cs : public BasePacket 	// 스토리 던전 스킬사용
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
		mp_skill_start_story_dungeon_cs() : BasePacket(mpe_cmd::skill_start_story_dungeon_cs)
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

	class mp_skill_start_story_dungeon_sc : public BasePacket 	// 스토리 던전 스킬사용
	{
	public:
		int64_t owner_uid {};
	public:
		int32_t usehp {};	// 사용 hp
	public:
		int32_t usemp{};	// 사용 mp
	public:
		int64_t send_time{};	// 서버 시간(패킷 전송 시)
	public:
		mpe_direction skill_dir{};	// 스킬 방향
	public:
		int32_t skill_id{};	// 스킬 id
	public:
		mpe_error result{};	// 스킬 결과
	public:
		int32_t current_hp{};	// 스킬 사용 후 hp
	public:
		int32_t current_mp{};	// 스킬 사용 후 mp
	private:
		bool flag_super_armor = false;
		mps_buff super_armor;	// 슈퍼 아머 정보
		mps_buff* p_super_armor = nullptr;
	public:
		bool has_super_armor() const
		{
			return flag_super_armor;
		}
		mps_buff* alloc_super_armor()
		{
			flag_super_armor = true;
			return &super_armor;
		}
		const mps_buff* get_super_armor() const
		{
			if (true == flag_super_armor)
			{
				if (nullptr == p_super_armor)
				{
					return &super_armor;
				}
				return p_super_armor;
			}
			return nullptr;
		}
		void set_super_armor(mps_buff* in_super_armor)
		{
			if (nullptr == p_super_armor)
			{
				p_super_armor = in_super_armor;
				flag_super_armor = true;
			}
		}
	public:
		int64_t skill_uid{};	// 스킬 uid

	public:
		mp_skill_start_story_dungeon_sc() : BasePacket(mpe_cmd::skill_start_story_dungeon_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &owner_uid );
			protocol::SerializeType(pBuffer, &usehp );
			protocol::SerializeType(pBuffer, &usemp);
			protocol::SerializeType(pBuffer, &send_time);
			protocol::SerializeEnum(pBuffer, &skill_dir);
			protocol::SerializeType(pBuffer, &skill_id);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &current_hp);
			protocol::SerializeType(pBuffer, &current_mp);
			protocol::SerializeType(pBuffer, &flag_super_armor);
			if (true == flag_super_armor)
			{
				if (nullptr != p_super_armor)
					protocol::SerializeType(pBuffer, p_super_armor);
				else
					protocol::SerializeType(pBuffer, &super_armor);
			}
			protocol::SerializeType(pBuffer, &skill_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
