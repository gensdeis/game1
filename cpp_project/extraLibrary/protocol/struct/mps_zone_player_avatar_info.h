#pragma once
#include <vector>
#include <string>
#include "mps_buff.h"

namespace mir3d
{
	class mps_zone_player_avatar_info 
	{
	public:
		std::string nick{};	// 닉네임
	public:
		int32_t level{};	// level
	public:
		int32_t avatar_id{};	// avatar table id
	public:
		uint8_t class_type{};	// enum table class type
	public:
		int32_t hp{};	// HP
	public:
		int32_t mp{};	// MP
	public:
		mpe_character_action action{};	// 캐릭터의액션상태
	public:
		mpe_move_type move_type{};
	public:
		std::vector<int32_t> list_equip{};	// 장착정보
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
		mps_zone_player_avatar_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &nick);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &avatar_id);
			protocol::SerializeType(pBuffer, &class_type);
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
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
