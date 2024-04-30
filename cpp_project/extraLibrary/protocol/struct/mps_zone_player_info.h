#pragma once
#include <vector>
#include <string>
#include "mps_equip_item_info.h"
#include "mps_buff.h"
#include "mps_avatar_info.h"
#include "mps_title_send_info.h"

namespace mir3d
{
	class mps_zone_player_info 
	{
	public:
		std::string nick{};	// 닉네임
	public:
		int32_t level{};	// level
	public:
		int32_t hp{};	// HP
	public:
		int32_t mp{};	// MP
	public:
		mpe_character_action action{};	// 캐릭터의액션상태
	public:
		mpe_move_type move_type{};
	public:
		std::vector<mps_equip_item_info> list_equip{};	// 장착정보
	public:
		int64_t puid{};	// party
	public:
		int32_t mhp{};	// maxHP
	public:
		int32_t mmp{};	// maxMP
	public:
		std::vector<mps_buff> buff_list{};
	public:
		int32_t pk_point{};	// pk죄악도
	public:
		mpe_pk_color color{};
	public:
		int32_t vehicle_id{};	// 탈것vid(11월버전임시)
	public:
		int32_t weight_id{};	// 무게테이블id
	public:
		int32_t curr_cell{};	// 현재 타일
	public:
		mpe_direction direction{};	// 방향정보
	public:
		int64_t guid{};	// 길드uid
	public:
		std::string guild_name{};	// 길드 이름
	public:
		float atk_speed{};	// 공속
	public:
		int32_t pet_id{};	// 펫아이디
	public:
		uint16_t customzing_data{};
	public:
		int32_t title_id{};	// 칭호 아이디
	public:
		uint8_t is_beginner_guild{};	// 0:false 1:true
	public:
		bool is_transform_avatar{};	// "아바타 변신 여부 = true 변신, false 변신 아님"
	private:
		bool flag_avatar_info = false;
		mps_avatar_info avatar_info;	// 아바타 정보
		mps_avatar_info* p_avatar_info = nullptr;
	public:
		bool has_avatar_info() const
		{
			return flag_avatar_info;
		}
		mps_avatar_info* alloc_avatar_info()
		{
			flag_avatar_info = true;
			return &avatar_info;
		}
		const mps_avatar_info* get_avatar_info() const
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
		void set_avatar_info(mps_avatar_info* in_avatar_info)
		{
			if (nullptr == p_avatar_info)
			{
				p_avatar_info = in_avatar_info;
				flag_avatar_info = true;
			}
		}
	public:
		uint8_t wanted_murder_grade{};	// 현상수배단계
	public:
		std::vector<uint8_t> guild_mark{};	// 문파 문장
	public:
		bool revive_request_state{};	// 부활 요청 상태
	public:
		int32_t reflection_id{};	// 화신 id
	public:
		std::vector<mps_title_send_info> list_title{};	// 칭호 아이디 리스트
	public:
		int64_t action_target_uid{};	// 캐릭터의액션상태 target uid
	public:
		int32_t gid{};	// 서버 gid
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_zone_player_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &nick);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &hp);
			protocol::SerializeType(pBuffer, &mp);
			protocol::SerializeEnum(pBuffer, &action);
			protocol::SerializeEnum(pBuffer, &move_type);
			protocol::SerializeType(pBuffer, &list_equip);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &mhp);
			protocol::SerializeType(pBuffer, &mmp);
			protocol::SerializeType(pBuffer, &buff_list);
			protocol::SerializeType(pBuffer, &pk_point);
			protocol::SerializeEnum(pBuffer, &color);
			protocol::SerializeType(pBuffer, &vehicle_id);
			protocol::SerializeType(pBuffer, &weight_id);
			protocol::SerializeType(pBuffer, &curr_cell);
			protocol::SerializeEnum(pBuffer, &direction);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &atk_speed);
			protocol::SerializeType(pBuffer, &pet_id);
			protocol::SerializeType(pBuffer, &customzing_data);
			protocol::SerializeType(pBuffer, &title_id);
			protocol::SerializeType(pBuffer, &is_beginner_guild);
			protocol::SerializeType(pBuffer, &is_transform_avatar);
			protocol::SerializeType(pBuffer, &flag_avatar_info);
			if (true == flag_avatar_info)
			{
				if (nullptr != p_avatar_info)
					protocol::SerializeType(pBuffer, p_avatar_info);
				else
					protocol::SerializeType(pBuffer, &avatar_info);
			}
			protocol::SerializeType(pBuffer, &wanted_murder_grade);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &revive_request_state);
			protocol::SerializeType(pBuffer, &reflection_id);
			protocol::SerializeType(pBuffer, &list_title);
			protocol::SerializeType(pBuffer, &action_target_uid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
