#pragma once
#include <vector>
#include <string>
#include "mps_character.h"
#include "mrpcs_meridians.h"
#include "mrpcs_enchant_stone_info.h"
#include "mrpcs_pk_record_info.h"
#include "mrpcs_character_ranking_info.h"
#include "mrpcs_adult_certification.h"
#include "mrpcs_teleport_area.h"
#include "mps_dictionary_info.h"
#include "mps_pickup_info.h"
#include "mrpcs_subscription_info.h"
#include "mrpcs_avatar_info.h"
#include "mrpcs_simple_mail_box.h"
#include "mps_item.h"
#include "mps_list_dictionary_info.h"
#include "mps_achieve_rate_info.h"
#include "mps_cash_shop_buy_count.h"
#include "mps_cart_item.h"
#include "mps_cash_exchange_product.h"
#include "mps_cash_package_product.h"
#include "mps_revive.h"
#include "mps_temp_reflection.h"
#include "mps_street_stall_info.h"
#include "mrpcs_account_ticket_item.h"
#include "mps_item.h"
#include "mps_item.h"

namespace mir3d
{
	class mrpcs_character_data 
	{
	public:
		int64_t auid{};
	public:
		std::string username{};
	public:
		int64_t channel_uid{};
	public:
		int32_t indun_id{};
	public:
		int32_t lasttime{};
	private:
		bool flag_character = false;
		mps_character character;
		mps_character* p_character = nullptr;
	public:
		bool has_character() const
		{
			return flag_character;
		}
		mps_character* alloc_character()
		{
			flag_character = true;
			return &character;
		}
		const mps_character* get_character() const
		{
			if (true == flag_character)
			{
				if (nullptr == p_character)
				{
					return &character;
				}
				return p_character;
			}
			return nullptr;
		}
		void set_character(mps_character* in_character)
		{
			if (nullptr == p_character)
			{
				p_character = in_character;
				flag_character = true;
			}
		}
	private:
		bool flag_meridians = false;
		mrpcs_meridians meridians;
		mrpcs_meridians* p_meridians = nullptr;
	public:
		bool has_meridians() const
		{
			return flag_meridians;
		}
		mrpcs_meridians* alloc_meridians()
		{
			flag_meridians = true;
			return &meridians;
		}
		const mrpcs_meridians* get_meridians() const
		{
			if (true == flag_meridians)
			{
				if (nullptr == p_meridians)
				{
					return &meridians;
				}
				return p_meridians;
			}
			return nullptr;
		}
		void set_meridians(mrpcs_meridians* in_meridians)
		{
			if (nullptr == p_meridians)
			{
				p_meridians = in_meridians;
				flag_meridians = true;
			}
		}
	private:
		bool flag_enchant_stone_info = false;
		mrpcs_enchant_stone_info enchant_stone_info;
		mrpcs_enchant_stone_info* p_enchant_stone_info = nullptr;
	public:
		bool has_enchant_stone_info() const
		{
			return flag_enchant_stone_info;
		}
		mrpcs_enchant_stone_info* alloc_enchant_stone_info()
		{
			flag_enchant_stone_info = true;
			return &enchant_stone_info;
		}
		const mrpcs_enchant_stone_info* get_enchant_stone_info() const
		{
			if (true == flag_enchant_stone_info)
			{
				if (nullptr == p_enchant_stone_info)
				{
					return &enchant_stone_info;
				}
				return p_enchant_stone_info;
			}
			return nullptr;
		}
		void set_enchant_stone_info(mrpcs_enchant_stone_info* in_enchant_stone_info)
		{
			if (nullptr == p_enchant_stone_info)
			{
				p_enchant_stone_info = in_enchant_stone_info;
				flag_enchant_stone_info = true;
			}
		}
	private:
		bool flag_pk_record_info = false;
		mrpcs_pk_record_info pk_record_info;
		mrpcs_pk_record_info* p_pk_record_info = nullptr;
	public:
		bool has_pk_record_info() const
		{
			return flag_pk_record_info;
		}
		mrpcs_pk_record_info* alloc_pk_record_info()
		{
			flag_pk_record_info = true;
			return &pk_record_info;
		}
		const mrpcs_pk_record_info* get_pk_record_info() const
		{
			if (true == flag_pk_record_info)
			{
				if (nullptr == p_pk_record_info)
				{
					return &pk_record_info;
				}
				return p_pk_record_info;
			}
			return nullptr;
		}
		void set_pk_record_info(mrpcs_pk_record_info* in_pk_record_info)
		{
			if (nullptr == p_pk_record_info)
			{
				p_pk_record_info = in_pk_record_info;
				flag_pk_record_info = true;
			}
		}
	private:
		bool flag_ranking_info = false;
		mrpcs_character_ranking_info ranking_info;
		mrpcs_character_ranking_info* p_ranking_info = nullptr;
	public:
		bool has_ranking_info() const
		{
			return flag_ranking_info;
		}
		mrpcs_character_ranking_info* alloc_ranking_info()
		{
			flag_ranking_info = true;
			return &ranking_info;
		}
		const mrpcs_character_ranking_info* get_ranking_info() const
		{
			if (true == flag_ranking_info)
			{
				if (nullptr == p_ranking_info)
				{
					return &ranking_info;
				}
				return p_ranking_info;
			}
			return nullptr;
		}
		void set_ranking_info(mrpcs_character_ranking_info* in_ranking_info)
		{
			if (nullptr == p_ranking_info)
			{
				p_ranking_info = in_ranking_info;
				flag_ranking_info = true;
			}
		}
	private:
		bool flag_adult_info = false;
		mrpcs_adult_certification adult_info;
		mrpcs_adult_certification* p_adult_info = nullptr;
	public:
		bool has_adult_info() const
		{
			return flag_adult_info;
		}
		mrpcs_adult_certification* alloc_adult_info()
		{
			flag_adult_info = true;
			return &adult_info;
		}
		const mrpcs_adult_certification* get_adult_info() const
		{
			if (true == flag_adult_info)
			{
				if (nullptr == p_adult_info)
				{
					return &adult_info;
				}
				return p_adult_info;
			}
			return nullptr;
		}
		void set_adult_info(mrpcs_adult_certification* in_adult_info)
		{
			if (nullptr == p_adult_info)
			{
				p_adult_info = in_adult_info;
				flag_adult_info = true;
			}
		}
	public:
		std::vector<mrpcs_teleport_area> teleport_area_list{};
	public:
		std::vector<mps_dictionary_info> dic_list{};
	public:
		std::vector<mps_pickup_info> auto_battle_pickup_list{};
	public:
		std::vector<mrpcs_subscription_info> subscription_info_list{};
	private:
		bool flag_avatar_info = false;
		mrpcs_avatar_info avatar_info;
		mrpcs_avatar_info* p_avatar_info = nullptr;
	public:
		bool has_avatar_info() const
		{
			return flag_avatar_info;
		}
		mrpcs_avatar_info* alloc_avatar_info()
		{
			flag_avatar_info = true;
			return &avatar_info;
		}
		const mrpcs_avatar_info* get_avatar_info() const
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
		void set_avatar_info(mrpcs_avatar_info* in_avatar_info)
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
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t cumulative_connection_time{};	// 접속유지시간
	private:
		bool flag_mail_box = false;
		mrpcs_simple_mail_box mail_box;
		mrpcs_simple_mail_box* p_mail_box = nullptr;
	public:
		bool has_mail_box() const
		{
			return flag_mail_box;
		}
		mrpcs_simple_mail_box* alloc_mail_box()
		{
			flag_mail_box = true;
			return &mail_box;
		}
		const mrpcs_simple_mail_box* get_mail_box() const
		{
			if (true == flag_mail_box)
			{
				if (nullptr == p_mail_box)
				{
					return &mail_box;
				}
				return p_mail_box;
			}
			return nullptr;
		}
		void set_mail_box(mrpcs_simple_mail_box* in_mail_box)
		{
			if (nullptr == p_mail_box)
			{
				p_mail_box = in_mail_box;
				flag_mail_box = true;
			}
		}
	public:
		int32_t worship_point{};
	public:
		int32_t last_worship_time{};
	public:
		std::vector<mps_item> list_mandala_stone{};
	public:
		int32_t dic_category{};
	public:
		mpe_dictionary_type dic_type{};
	public:
		std::vector<mps_list_dictionary_info> list_dic_info{};
	public:
		std::vector<mps_achieve_rate_info> list_dic_rate{};
	public:
		std::vector<mps_cash_shop_buy_count> buy_count_list{};
	public:
		std::vector<mps_cart_item> cart_item_list{};
	public:
		std::vector<mps_cash_exchange_product> exchange_product{};
	public:
		std::vector<mps_cash_package_product> package_product{};
	public:
		std::vector<mps_revive> list_revive{};
	public:
		std::vector<mps_temp_reflection> list_temp_reflection{};
	private:
		bool flag_street_stall_info = false;
		mps_street_stall_info street_stall_info;
		mps_street_stall_info* p_street_stall_info = nullptr;
	public:
		bool has_street_stall_info() const
		{
			return flag_street_stall_info;
		}
		mps_street_stall_info* alloc_street_stall_info()
		{
			flag_street_stall_info = true;
			return &street_stall_info;
		}
		const mps_street_stall_info* get_street_stall_info() const
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
		void set_street_stall_info(mps_street_stall_info* in_street_stall_info)
		{
			if (nullptr == p_street_stall_info)
			{
				p_street_stall_info = in_street_stall_info;
				flag_street_stall_info = true;
			}
		}
	public:
		int32_t security_level{};
	public:
		mpe_os_type os_type{};
	public:
		int32_t mentor_genealogy{};
	public:
		std::string linked_wallet_address{};	// 월렛연동주소
	private:
		bool flag_account_ticket_item = false;
		mrpcs_account_ticket_item account_ticket_item;
		mrpcs_account_ticket_item* p_account_ticket_item = nullptr;
	public:
		bool has_account_ticket_item() const
		{
			return flag_account_ticket_item;
		}
		mrpcs_account_ticket_item* alloc_account_ticket_item()
		{
			flag_account_ticket_item = true;
			return &account_ticket_item;
		}
		const mrpcs_account_ticket_item* get_account_ticket_item() const
		{
			if (true == flag_account_ticket_item)
			{
				if (nullptr == p_account_ticket_item)
				{
					return &account_ticket_item;
				}
				return p_account_ticket_item;
			}
			return nullptr;
		}
		void set_account_ticket_item(mrpcs_account_ticket_item* in_account_ticket_item)
		{
			if (nullptr == p_account_ticket_item)
			{
				p_account_ticket_item = in_account_ticket_item;
				flag_account_ticket_item = true;
			}
		}
	public:
		std::vector<mps_item> list_expert_equipment_stone{};	// "신기 착용된 용령석 아이템 목록"
	public:
		std::vector<mps_item> list_season_mandala_stone{};	// 시즌 만다라에 장착된 용령석 아이템 목록
	public:
		int32_t season_mandala_id{};	// 시즌 만다라 시즌 아이디
	public:
		mpe_season_mandala_state season_mandala_open_state{};	// 시즌 만다라 오픈 상태(0:기본값 1:오픈 2:종료)

	public:
		mrpcs_character_data()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &indun_id);
			protocol::SerializeType(pBuffer, &lasttime);
			protocol::SerializeType(pBuffer, &flag_character);
			if (true == flag_character)
			{
				if (nullptr != p_character)
					protocol::SerializeType(pBuffer, p_character);
				else
					protocol::SerializeType(pBuffer, &character);
			}
			protocol::SerializeType(pBuffer, &flag_meridians);
			if (true == flag_meridians)
			{
				if (nullptr != p_meridians)
					protocol::SerializeType(pBuffer, p_meridians);
				else
					protocol::SerializeType(pBuffer, &meridians);
			}
			protocol::SerializeType(pBuffer, &flag_enchant_stone_info);
			if (true == flag_enchant_stone_info)
			{
				if (nullptr != p_enchant_stone_info)
					protocol::SerializeType(pBuffer, p_enchant_stone_info);
				else
					protocol::SerializeType(pBuffer, &enchant_stone_info);
			}
			protocol::SerializeType(pBuffer, &flag_pk_record_info);
			if (true == flag_pk_record_info)
			{
				if (nullptr != p_pk_record_info)
					protocol::SerializeType(pBuffer, p_pk_record_info);
				else
					protocol::SerializeType(pBuffer, &pk_record_info);
			}
			protocol::SerializeType(pBuffer, &flag_ranking_info);
			if (true == flag_ranking_info)
			{
				if (nullptr != p_ranking_info)
					protocol::SerializeType(pBuffer, p_ranking_info);
				else
					protocol::SerializeType(pBuffer, &ranking_info);
			}
			protocol::SerializeType(pBuffer, &flag_adult_info);
			if (true == flag_adult_info)
			{
				if (nullptr != p_adult_info)
					protocol::SerializeType(pBuffer, p_adult_info);
				else
					protocol::SerializeType(pBuffer, &adult_info);
			}
			protocol::SerializeType(pBuffer, &teleport_area_list);
			protocol::SerializeType(pBuffer, &dic_list);
			protocol::SerializeType(pBuffer, &auto_battle_pickup_list);
			protocol::SerializeType(pBuffer, &subscription_info_list);
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
			protocol::SerializeType(pBuffer, &cumulative_connection_time);
			protocol::SerializeType(pBuffer, &flag_mail_box);
			if (true == flag_mail_box)
			{
				if (nullptr != p_mail_box)
					protocol::SerializeType(pBuffer, p_mail_box);
				else
					protocol::SerializeType(pBuffer, &mail_box);
			}
			protocol::SerializeType(pBuffer, &worship_point);
			protocol::SerializeType(pBuffer, &last_worship_time);
			protocol::SerializeType(pBuffer, &list_mandala_stone);
			protocol::SerializeType(pBuffer, &dic_category);
			protocol::SerializeEnum(pBuffer, &dic_type);
			protocol::SerializeType(pBuffer, &list_dic_info);
			protocol::SerializeType(pBuffer, &list_dic_rate);
			protocol::SerializeType(pBuffer, &buy_count_list);
			protocol::SerializeType(pBuffer, &cart_item_list);
			protocol::SerializeType(pBuffer, &exchange_product);
			protocol::SerializeType(pBuffer, &package_product);
			protocol::SerializeType(pBuffer, &list_revive);
			protocol::SerializeType(pBuffer, &list_temp_reflection);
			protocol::SerializeType(pBuffer, &flag_street_stall_info);
			if (true == flag_street_stall_info)
			{
				if (nullptr != p_street_stall_info)
					protocol::SerializeType(pBuffer, p_street_stall_info);
				else
					protocol::SerializeType(pBuffer, &street_stall_info);
			}
			protocol::SerializeType(pBuffer, &security_level);
			protocol::SerializeEnum(pBuffer, &os_type);
			protocol::SerializeType(pBuffer, &mentor_genealogy);
			protocol::SerializeType(pBuffer, &linked_wallet_address);
			protocol::SerializeType(pBuffer, &flag_account_ticket_item);
			if (true == flag_account_ticket_item)
			{
				if (nullptr != p_account_ticket_item)
					protocol::SerializeType(pBuffer, p_account_ticket_item);
				else
					protocol::SerializeType(pBuffer, &account_ticket_item);
			}
			protocol::SerializeType(pBuffer, &list_expert_equipment_stone);
			protocol::SerializeType(pBuffer, &list_season_mandala_stone);
			protocol::SerializeType(pBuffer, &season_mandala_id);
			protocol::SerializeEnum(pBuffer, &season_mandala_open_state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
