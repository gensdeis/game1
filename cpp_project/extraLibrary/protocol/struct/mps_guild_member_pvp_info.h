#pragma once
#include <vector>
#include <string>
#include "mps_vector.h"

namespace mir3d
{
	class mps_guild_member_pvp_info 
	{
	public:
		int64_t member_cuid{};
	public:
		std::string member_nickname{};	// 문파원 닉네임
	public:
		int64_t enemy_cuid{};
	public:
		std::string enemy_nickname{};	// 상대 닉네임
	public:
		int32_t enemy_level{};	// 상대 레벨
	public:
		int32_t enemy_tid{};	// 상대 직업 ID
	public:
		int32_t enemy_expert_level{};	// "상대 전직 레벨"
	public:
		int32_t enemy_chao_point{};	// "상대 카오 포인트"
	public:
		int64_t enemy_guid{};	// "상대 문파 UID"
	public:
		std::string enemy_guild_name{};	// "상대 문파 이름"
	public:
		std::vector<uint8_t> enemy_guild_mark{};	// 상대 문파 마크
	public:
		bool result{};	// "true:처치, false "
	public:
		int64_t reg_time{};	// 발생 시간
	public:
		uint16_t ch_id{};	// "채널id"
	public:
		int32_t zone_id{};	// "MapID"
	private:
		bool flag_pos = false;
		mps_vector pos;	// "위치 정보"
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

	public:
		mps_guild_member_pvp_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &member_cuid);
			protocol::SerializeType(pBuffer, &member_nickname);
			protocol::SerializeType(pBuffer, &enemy_cuid);
			protocol::SerializeType(pBuffer, &enemy_nickname);
			protocol::SerializeType(pBuffer, &enemy_level);
			protocol::SerializeType(pBuffer, &enemy_tid);
			protocol::SerializeType(pBuffer, &enemy_expert_level);
			protocol::SerializeType(pBuffer, &enemy_chao_point);
			protocol::SerializeType(pBuffer, &enemy_guid);
			protocol::SerializeType(pBuffer, &enemy_guild_name);
			protocol::SerializeType(pBuffer, &enemy_guild_mark);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &reg_time);
			protocol::SerializeType(pBuffer, &ch_id);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &flag_pos);
			if (true == flag_pos)
			{
				if (nullptr != p_pos)
					protocol::SerializeType(pBuffer, p_pos);
				else
					protocol::SerializeType(pBuffer, &pos);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
