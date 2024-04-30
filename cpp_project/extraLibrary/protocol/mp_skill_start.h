#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_target_info.h"
#include "struct/mps_buff.h"
#include "struct/mps_enemy_error.h"

namespace mir3d
{
	class mp_skill_start_cs : public BasePacket 
	{
	public:
		int32_t skill_id{};	// 스킬 id
	public:
		mpe_direction skill_dir{};	// 스킬 방향
	public:
		int64_t target_uid{};	// 타겟 uid
	public:
		int32_t target_tile_index{};	// 스킬 타겟 cell index
	public:
		std::vector<int64_t> target_uid_list{};	// 타겟 uid list

	public:
		mp_skill_start_cs() : BasePacket(mpe_cmd::skill_start_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &skill_id);
			protocol::SerializeEnum(pBuffer, &skill_dir);
			protocol::SerializeType(pBuffer, &target_uid);
			protocol::SerializeType(pBuffer, &target_tile_index);
			protocol::SerializeType(pBuffer, &target_uid_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_skill_start_sc : public BasePacket 
	{
	public:
		int64_t owner_uid {};	// player uid
	public:
		int32_t owner_tile_index{};	// player cell index
	public:
		int32_t usehp {};	// 사용 hp
	public:
		int32_t usemp{};	// 사용 mp
	public:
		int64_t send_time{};	// 서버 시간(패킷 전송 시)
	public:
		int64_t target_uid{};	// 타겟 uid
	public:
		int32_t target_tile_index{};	// 타겟 cell index
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
		bool flag_target_info = false;
		mps_target_info target_info;	// 타겟 정보(result가 에러 일 경우)
		mps_target_info* p_target_info = nullptr;
	public:
		bool has_target_info() const
		{
			return flag_target_info;
		}
		mps_target_info* alloc_target_info()
		{
			flag_target_info = true;
			return &target_info;
		}
		const mps_target_info* get_target_info() const
		{
			if (true == flag_target_info)
			{
				if (nullptr == p_target_info)
				{
					return &target_info;
				}
				return p_target_info;
			}
			return nullptr;
		}
		void set_target_info(mps_target_info* in_target_info)
		{
			if (nullptr == p_target_info)
			{
				p_target_info = in_target_info;
				flag_target_info = true;
			}
		}
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
		mpe_fsm_type fsm_type{};	// 몬스터 fsm type (result가 에러 일 경우)
	public:
		int64_t skill_uid{};	// 스킬 uid
	public:
		std::vector<mps_enemy_error> error_list{};	// 타겟 에러 리스트
	public:
		int32_t skill_level{};	// 스킬레벨

	public:
		mp_skill_start_sc() : BasePacket(mpe_cmd::skill_start_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &owner_uid );
			protocol::SerializeType(pBuffer, &owner_tile_index);
			protocol::SerializeType(pBuffer, &usehp );
			protocol::SerializeType(pBuffer, &usemp);
			protocol::SerializeType(pBuffer, &send_time);
			protocol::SerializeType(pBuffer, &target_uid);
			protocol::SerializeType(pBuffer, &target_tile_index);
			protocol::SerializeEnum(pBuffer, &skill_dir);
			protocol::SerializeType(pBuffer, &skill_id);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &current_hp);
			protocol::SerializeType(pBuffer, &current_mp);
			protocol::SerializeType(pBuffer, &flag_target_info);
			if (true == flag_target_info)
			{
				if (nullptr != p_target_info)
					protocol::SerializeType(pBuffer, p_target_info);
				else
					protocol::SerializeType(pBuffer, &target_info);
			}
			protocol::SerializeType(pBuffer, &flag_super_armor);
			if (true == flag_super_armor)
			{
				if (nullptr != p_super_armor)
					protocol::SerializeType(pBuffer, p_super_armor);
				else
					protocol::SerializeType(pBuffer, &super_armor);
			}
			protocol::SerializeEnum(pBuffer, &fsm_type);
			protocol::SerializeType(pBuffer, &skill_uid);
			protocol::SerializeType(pBuffer, &error_list);
			protocol::SerializeType(pBuffer, &skill_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
