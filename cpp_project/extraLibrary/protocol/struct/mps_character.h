#pragma once
#include <vector>
#include <string>
#include "mps_zone_info.h"
#include "mps_character_stat.h"
#include "mps_inventory.h"
#include "mps_questbook.h"
#include "mps_skillbook.h"
#include "mps_item.h"
#include "mps_profesion.h"
#include "mps_daily_content.h"
#include "mps_dungeon.h"
#include "mps_db_buff.h"
#include "mps_vehicle.h"
#include "mps_item.h"
#include "mps_pet_info.h"
#include "mps_ranking_history.h"
#include "mps_teleport_area.h"
#include "mps_cash_info.h"
#include "mps_cash_limited_product.h"
#include "mps_dic_stat.h"
#include "mps_avatar_info.h"
#include "mps_seasonpass.h"
#include "mps_seasonpass_challenge.h"
#include "mps_avatar.h"
#include "mps_illusion_dungeon.h"
#include "mps_reflection.h"
#include "mps_mandala_layer_info.h"
#include "mps_mandala_node_info.h"
#include "mps_mandala_layer_info.h"
#include "mps_mandala_node_info.h"
#include "mps_title_info.h"
#include "mps_make_item.h"
#include "mps_make_item.h"
#include "mps_expert_equipment_info.h"
#include "mps_boss_dungeon_record.h"
#include "mps_mandala_layer_info.h"
#include "mps_mandala_node_info.h"
#include "mps_season_mandala_reward_info.h"

namespace mir3d
{
	class mps_character 
	{
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		int32_t id{};
	private:
		bool flag_zone = false;
		mps_zone_info zone;
		mps_zone_info* p_zone = nullptr;
	public:
		bool has_zone() const
		{
			return flag_zone;
		}
		mps_zone_info* alloc_zone()
		{
			flag_zone = true;
			return &zone;
		}
		const mps_zone_info* get_zone() const
		{
			if (true == flag_zone)
			{
				if (nullptr == p_zone)
				{
					return &zone;
				}
				return p_zone;
			}
			return nullptr;
		}
		void set_zone(mps_zone_info* in_zone)
		{
			if (nullptr == p_zone)
			{
				p_zone = in_zone;
				flag_zone = true;
			}
		}
	private:
		bool flag_stat = false;
		mps_character_stat stat;
		mps_character_stat* p_stat = nullptr;
	public:
		bool has_stat() const
		{
			return flag_stat;
		}
		mps_character_stat* alloc_stat()
		{
			flag_stat = true;
			return &stat;
		}
		const mps_character_stat* get_stat() const
		{
			if (true == flag_stat)
			{
				if (nullptr == p_stat)
				{
					return &stat;
				}
				return p_stat;
			}
			return nullptr;
		}
		void set_stat(mps_character_stat* in_stat)
		{
			if (nullptr == p_stat)
			{
				p_stat = in_stat;
				flag_stat = true;
			}
		}
	private:
		bool flag_inven = false;
		mps_inventory inven;
		mps_inventory* p_inven = nullptr;
	public:
		bool has_inven() const
		{
			return flag_inven;
		}
		mps_inventory* alloc_inven()
		{
			flag_inven = true;
			return &inven;
		}
		const mps_inventory* get_inven() const
		{
			if (true == flag_inven)
			{
				if (nullptr == p_inven)
				{
					return &inven;
				}
				return p_inven;
			}
			return nullptr;
		}
		void set_inven(mps_inventory* in_inven)
		{
			if (nullptr == p_inven)
			{
				p_inven = in_inven;
				flag_inven = true;
			}
		}
	private:
		bool flag_questbook = false;
		mps_questbook questbook;
		mps_questbook* p_questbook = nullptr;
	public:
		bool has_questbook() const
		{
			return flag_questbook;
		}
		mps_questbook* alloc_questbook()
		{
			flag_questbook = true;
			return &questbook;
		}
		const mps_questbook* get_questbook() const
		{
			if (true == flag_questbook)
			{
				if (nullptr == p_questbook)
				{
					return &questbook;
				}
				return p_questbook;
			}
			return nullptr;
		}
		void set_questbook(mps_questbook* in_questbook)
		{
			if (nullptr == p_questbook)
			{
				p_questbook = in_questbook;
				flag_questbook = true;
			}
		}
	private:
		bool flag_skillbook = false;
		mps_skillbook skillbook;
		mps_skillbook* p_skillbook = nullptr;
	public:
		bool has_skillbook() const
		{
			return flag_skillbook;
		}
		mps_skillbook* alloc_skillbook()
		{
			flag_skillbook = true;
			return &skillbook;
		}
		const mps_skillbook* get_skillbook() const
		{
			if (true == flag_skillbook)
			{
				if (nullptr == p_skillbook)
				{
					return &skillbook;
				}
				return p_skillbook;
			}
			return nullptr;
		}
		void set_skillbook(mps_skillbook* in_skillbook)
		{
			if (nullptr == p_skillbook)
			{
				p_skillbook = in_skillbook;
				flag_skillbook = true;
			}
		}
	public:
		std::vector<int32_t> list_goods{};
	public:
		int64_t exp{};
	public:
		int64_t expert_exp{};
	public:
		std::vector<mps_item> list_equip{};
	public:
		int64_t puid{};
	public:
		int32_t pk_setup{};
	public:
		int32_t indun_id{};
	public:
		int32_t protect_equip{};
	public:
		int32_t power{};
	public:
		std::vector<int32_t> list_repute_quest{};
	public:
		bool new_mail{};
	public:
		std::vector<int32_t> list_daily_content{};
	public:
		std::vector<mps_profesion> list_profesion{};
	private:
		bool flag_daily_content = false;
		mps_daily_content daily_content;
		mps_daily_content* p_daily_content = nullptr;
	public:
		bool has_daily_content() const
		{
			return flag_daily_content;
		}
		mps_daily_content* alloc_daily_content()
		{
			flag_daily_content = true;
			return &daily_content;
		}
		const mps_daily_content* get_daily_content() const
		{
			if (true == flag_daily_content)
			{
				if (nullptr == p_daily_content)
				{
					return &daily_content;
				}
				return p_daily_content;
			}
			return nullptr;
		}
		void set_daily_content(mps_daily_content* in_daily_content)
		{
			if (nullptr == p_daily_content)
			{
				p_daily_content = in_daily_content;
				flag_daily_content = true;
			}
		}
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		int64_t guild_next_available_join_time{};
	public:
		int32_t account_storage_buy_date{};
	public:
		uint16_t private_storage_size{};
	public:
		std::vector<mps_dungeon> list_dungeon{};
	public:
		std::vector<mps_db_buff> list_buff{};
	public:
		std::vector<int32_t> list_guild_skill{};
	public:
		std::vector<mps_vehicle> list_vehicle{};
	public:
		std::vector<mps_item> list_equip_vehicle{};
	public:
		int32_t cur_vehicle{};
	public:
		std::vector<mps_pet_info> list_pet_info{};
	public:
		int64_t mentor_cuid{};
	public:
		mpe_mentor_type mentor_type{};
	public:
		int64_t mentor_next_available_join_time{};
	public:
		std::vector<uint16_t> customizing_data{};	// 0 - 여 / 1 - 남
	public:
		std::vector<mps_ranking_history> list_ranking{};
	public:
		int32_t title{};
	public:
		uint8_t show_costume{};	// table enum COSTUME_TYPE 참고
	public:
		std::vector<mps_teleport_area> list_saved_teleport{};
	private:
		bool flag_cash_info = false;
		mps_cash_info cash_info;
		mps_cash_info* p_cash_info = nullptr;
	public:
		bool has_cash_info() const
		{
			return flag_cash_info;
		}
		mps_cash_info* alloc_cash_info()
		{
			flag_cash_info = true;
			return &cash_info;
		}
		const mps_cash_info* get_cash_info() const
		{
			if (true == flag_cash_info)
			{
				if (nullptr == p_cash_info)
				{
					return &cash_info;
				}
				return p_cash_info;
			}
			return nullptr;
		}
		void set_cash_info(mps_cash_info* in_cash_info)
		{
			if (nullptr == p_cash_info)
			{
				p_cash_info = in_cash_info;
				flag_cash_info = true;
			}
		}
	public:
		std::vector<mps_cash_limited_product> cash_limited_products{};
	public:
		int64_t auto_battle_free_time{};
	public:
		int64_t auto_battle_pay_time{};
	public:
		int64_t auto_battle_login_time{};
	public:
		int64_t auto_battle_logout_time{};
	public:
		std::vector<mps_dic_stat> dictionary_stat{};	// 도감으로 획득한 스텟정보
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
		bool first_login{};	// 최초 접속 유무
	public:
		uint16_t treasureboxkey_reset_count{};
	public:
		int64_t treasureboxkey_reset_time{};
	public:
		mpe_pet_team pet_team{};	// 펫 선택 팀
	public:
		std::vector<mps_seasonpass> list_seasonpass{};	// 시즌패스
	public:
		std::vector<mps_seasonpass_challenge> list_challenge{};	// 시즌도전과제
	public:
		std::vector<mps_avatar> list_avatar{};	// 보유중인 아바타
	public:
		std::vector<mps_illusion_dungeon> list_illusion{};	// 환상비경
	public:
		std::vector<mps_reflection> list_reflection{};	// 보유중인 화신
	public:
		std::vector<uint8_t> list_skill_force{};	// 내공
	public:
		std::vector<int32_t> list_special_move_slot{};	// 필살기 슬롯
	public:
		std::vector<mps_mandala_layer_info> list_layer{};	// 만다라 레이어
	public:
		std::vector<mps_mandala_node_info> list_node{};	// 만다라 노드
	public:
		std::vector<mps_mandala_layer_info> list_master_layer{};	// 장인만다라 레이어
	public:
		std::vector<mps_mandala_node_info> list_master_node{};	// 장인만다라 노드
	public:
		std::vector<mps_title_info> list_title{};	// 보유중인 칭호
	public:
		bool send_nickname_disable{};	// 공지 닉네임 표시 여부
	public:
		int64_t darksteelbox_staking{};	// 흑철상자_비곡점령_보관수량
	public:
		std::vector<mps_make_item> list_character_make_item{};	// 제작횟수(캐릭터)
	public:
		std::vector<mps_make_item> list_server_make_item{};	// 제작횟수(서버)
	public:
		int64_t server_relocation_time{};	// 서버 이전 쿨타임
	public:
		uint8_t is_delete{};
	public:
		std::vector<mps_expert_equipment_info> expert_equipments{};	// "신기목록 mp_expert_equipment_info로 따로 전달"
	public:
		std::vector<mps_boss_dungeon_record> record_list{};	// record 리스트
	public:
		std::vector<mps_mandala_layer_info> list_season_layer{};	// 시즌 만다라 레이어
	public:
		std::vector<mps_mandala_node_info> list_season_node{};	// 시즌 만다라 노드
	public:
		std::vector<mps_season_mandala_reward_info> list_season_mandala_reward{};	// 시즌 만다라 캐릭터보상 정보리스트

	public:
		mps_character()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &flag_zone);
			if (true == flag_zone)
			{
				if (nullptr != p_zone)
					protocol::SerializeType(pBuffer, p_zone);
				else
					protocol::SerializeType(pBuffer, &zone);
			}
			protocol::SerializeType(pBuffer, &flag_stat);
			if (true == flag_stat)
			{
				if (nullptr != p_stat)
					protocol::SerializeType(pBuffer, p_stat);
				else
					protocol::SerializeType(pBuffer, &stat);
			}
			protocol::SerializeType(pBuffer, &flag_inven);
			if (true == flag_inven)
			{
				if (nullptr != p_inven)
					protocol::SerializeType(pBuffer, p_inven);
				else
					protocol::SerializeType(pBuffer, &inven);
			}
			protocol::SerializeType(pBuffer, &flag_questbook);
			if (true == flag_questbook)
			{
				if (nullptr != p_questbook)
					protocol::SerializeType(pBuffer, p_questbook);
				else
					protocol::SerializeType(pBuffer, &questbook);
			}
			protocol::SerializeType(pBuffer, &flag_skillbook);
			if (true == flag_skillbook)
			{
				if (nullptr != p_skillbook)
					protocol::SerializeType(pBuffer, p_skillbook);
				else
					protocol::SerializeType(pBuffer, &skillbook);
			}
			protocol::SerializeType(pBuffer, &list_goods);
			protocol::SerializeType(pBuffer, &exp);
			protocol::SerializeType(pBuffer, &expert_exp);
			protocol::SerializeType(pBuffer, &list_equip);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &pk_setup);
			protocol::SerializeType(pBuffer, &indun_id);
			protocol::SerializeType(pBuffer, &protect_equip);
			protocol::SerializeType(pBuffer, &power);
			protocol::SerializeType(pBuffer, &list_repute_quest);
			protocol::SerializeType(pBuffer, &new_mail);
			protocol::SerializeType(pBuffer, &list_daily_content);
			protocol::SerializeType(pBuffer, &list_profesion);
			protocol::SerializeType(pBuffer, &flag_daily_content);
			if (true == flag_daily_content)
			{
				if (nullptr != p_daily_content)
					protocol::SerializeType(pBuffer, p_daily_content);
				else
					protocol::SerializeType(pBuffer, &daily_content);
			}
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &guild_next_available_join_time);
			protocol::SerializeType(pBuffer, &account_storage_buy_date);
			protocol::SerializeType(pBuffer, &private_storage_size);
			protocol::SerializeType(pBuffer, &list_dungeon);
			protocol::SerializeType(pBuffer, &list_buff);
			protocol::SerializeType(pBuffer, &list_guild_skill);
			protocol::SerializeType(pBuffer, &list_vehicle);
			protocol::SerializeType(pBuffer, &list_equip_vehicle);
			protocol::SerializeType(pBuffer, &cur_vehicle);
			protocol::SerializeType(pBuffer, &list_pet_info);
			protocol::SerializeType(pBuffer, &mentor_cuid);
			protocol::SerializeEnum(pBuffer, &mentor_type);
			protocol::SerializeType(pBuffer, &mentor_next_available_join_time);
			protocol::SerializeType(pBuffer, &customizing_data);
			protocol::SerializeType(pBuffer, &list_ranking);
			protocol::SerializeType(pBuffer, &title);
			protocol::SerializeType(pBuffer, &show_costume);
			protocol::SerializeType(pBuffer, &list_saved_teleport);
			protocol::SerializeType(pBuffer, &flag_cash_info);
			if (true == flag_cash_info)
			{
				if (nullptr != p_cash_info)
					protocol::SerializeType(pBuffer, p_cash_info);
				else
					protocol::SerializeType(pBuffer, &cash_info);
			}
			protocol::SerializeType(pBuffer, &cash_limited_products);
			protocol::SerializeType(pBuffer, &auto_battle_free_time);
			protocol::SerializeType(pBuffer, &auto_battle_pay_time);
			protocol::SerializeType(pBuffer, &auto_battle_login_time);
			protocol::SerializeType(pBuffer, &auto_battle_logout_time);
			protocol::SerializeType(pBuffer, &dictionary_stat);
			protocol::SerializeType(pBuffer, &is_transform_avatar);
			protocol::SerializeType(pBuffer, &flag_avatar_info);
			if (true == flag_avatar_info)
			{
				if (nullptr != p_avatar_info)
					protocol::SerializeType(pBuffer, p_avatar_info);
				else
					protocol::SerializeType(pBuffer, &avatar_info);
			}
			protocol::SerializeType(pBuffer, &first_login);
			protocol::SerializeType(pBuffer, &treasureboxkey_reset_count);
			protocol::SerializeType(pBuffer, &treasureboxkey_reset_time);
			protocol::SerializeEnum(pBuffer, &pet_team);
			protocol::SerializeType(pBuffer, &list_seasonpass);
			protocol::SerializeType(pBuffer, &list_challenge);
			protocol::SerializeType(pBuffer, &list_avatar);
			protocol::SerializeType(pBuffer, &list_illusion);
			protocol::SerializeType(pBuffer, &list_reflection);
			protocol::SerializeType(pBuffer, &list_skill_force);
			protocol::SerializeType(pBuffer, &list_special_move_slot);
			protocol::SerializeType(pBuffer, &list_layer);
			protocol::SerializeType(pBuffer, &list_node);
			protocol::SerializeType(pBuffer, &list_master_layer);
			protocol::SerializeType(pBuffer, &list_master_node);
			protocol::SerializeType(pBuffer, &list_title);
			protocol::SerializeType(pBuffer, &send_nickname_disable);
			protocol::SerializeType(pBuffer, &darksteelbox_staking);
			protocol::SerializeType(pBuffer, &list_character_make_item);
			protocol::SerializeType(pBuffer, &list_server_make_item);
			protocol::SerializeType(pBuffer, &server_relocation_time);
			protocol::SerializeType(pBuffer, &is_delete);
			protocol::SerializeType(pBuffer, &expert_equipments);
			protocol::SerializeType(pBuffer, &record_list);
			protocol::SerializeType(pBuffer, &list_season_layer);
			protocol::SerializeType(pBuffer, &list_season_node);
			protocol::SerializeType(pBuffer, &list_season_mandala_reward);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
