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
#include "mps_vehicle.h"
#include "mps_item.h"
#include "mps_pet_info.h"
#include "mps_cash_info.h"
#include "mps_cash_limited_product.h"
#include "mps_seasonpass.h"
#include "mps_seasonpass_challenge.h"
#include "mps_illusion_dungeon.h"
#include "mps_reflection.h"
#include "mps_temp_reflection.h"
#include "mrpcs_item_stone_pair.h"
#include "mps_title_info.h"
#include "mps_expert_equipment_info.h"

namespace mir3d
{
	class mrpcs_character 
	{
	public:
		int64_t auid{};
	public:
		std::string username{};
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
		std::vector<mps_item> list_equip{};
	public:
		int32_t power{};
	public:
		std::vector<int32_t> list_repute_quest{};
	public:
		std::vector<mps_profesion> list_profesion{};
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
		std::vector<mps_vehicle> list_vehicle{};
	public:
		std::vector<mps_item> list_equip_vehicle{};
	public:
		int32_t cur_vehicle{};
	public:
		std::vector<mps_pet_info> list_pet_info{};
	public:
		int32_t title{};
	private:
		bool flag_cash_info = false;
		mps_cash_info cash_info;	// 점권 정보
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
		mpe_pet_team pet_team{};
	private:
		bool flag_seasonpass = false;
		mps_seasonpass seasonpass;
		mps_seasonpass* p_seasonpass = nullptr;
	public:
		bool has_seasonpass() const
		{
			return flag_seasonpass;
		}
		mps_seasonpass* alloc_seasonpass()
		{
			flag_seasonpass = true;
			return &seasonpass;
		}
		const mps_seasonpass* get_seasonpass() const
		{
			if (true == flag_seasonpass)
			{
				if (nullptr == p_seasonpass)
				{
					return &seasonpass;
				}
				return p_seasonpass;
			}
			return nullptr;
		}
		void set_seasonpass(mps_seasonpass* in_seasonpass)
		{
			if (nullptr == p_seasonpass)
			{
				p_seasonpass = in_seasonpass;
				flag_seasonpass = true;
			}
		}
	public:
		std::vector<mps_seasonpass_challenge> list_challenge{};
	public:
		std::vector<mps_illusion_dungeon> list_illusion{};
	public:
		std::vector<mps_reflection> list_reflection{};
	public:
		std::vector<uint8_t> list_skill_force{};
	public:
		std::vector<int32_t> list_special_move_slot{};
	public:
		std::vector<mps_temp_reflection> list_temp_reflection{};
	public:
		std::vector<mrpcs_item_stone_pair> list_pair_info{};	// 아이템과 용령석 매칭 정보
	public:
		int32_t reg_datetime{};
	public:
		std::vector<mps_title_info> list_title{};
	public:
		int64_t expert_exp{};	// "전직경험치(진기)"
	public:
		std::vector<mps_expert_equipment_info> list_expert_equipment{};

	public:
		mrpcs_character()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &username);
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
			protocol::SerializeType(pBuffer, &list_equip);
			protocol::SerializeType(pBuffer, &power);
			protocol::SerializeType(pBuffer, &list_repute_quest);
			protocol::SerializeType(pBuffer, &list_profesion);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &guild_next_available_join_time);
			protocol::SerializeType(pBuffer, &account_storage_buy_date);
			protocol::SerializeType(pBuffer, &private_storage_size);
			protocol::SerializeType(pBuffer, &list_vehicle);
			protocol::SerializeType(pBuffer, &list_equip_vehicle);
			protocol::SerializeType(pBuffer, &cur_vehicle);
			protocol::SerializeType(pBuffer, &list_pet_info);
			protocol::SerializeType(pBuffer, &title);
			protocol::SerializeType(pBuffer, &flag_cash_info);
			if (true == flag_cash_info)
			{
				if (nullptr != p_cash_info)
					protocol::SerializeType(pBuffer, p_cash_info);
				else
					protocol::SerializeType(pBuffer, &cash_info);
			}
			protocol::SerializeType(pBuffer, &cash_limited_products);
			protocol::SerializeEnum(pBuffer, &pet_team);
			protocol::SerializeType(pBuffer, &flag_seasonpass);
			if (true == flag_seasonpass)
			{
				if (nullptr != p_seasonpass)
					protocol::SerializeType(pBuffer, p_seasonpass);
				else
					protocol::SerializeType(pBuffer, &seasonpass);
			}
			protocol::SerializeType(pBuffer, &list_challenge);
			protocol::SerializeType(pBuffer, &list_illusion);
			protocol::SerializeType(pBuffer, &list_reflection);
			protocol::SerializeType(pBuffer, &list_skill_force);
			protocol::SerializeType(pBuffer, &list_special_move_slot);
			protocol::SerializeType(pBuffer, &list_temp_reflection);
			protocol::SerializeType(pBuffer, &list_pair_info);
			protocol::SerializeType(pBuffer, &reg_datetime);
			protocol::SerializeType(pBuffer, &list_title);
			protocol::SerializeType(pBuffer, &expert_exp);
			protocol::SerializeType(pBuffer, &list_expert_equipment);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
