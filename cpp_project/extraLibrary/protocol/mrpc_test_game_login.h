#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_info.h"
#include "struct/mps_character.h"
#include "struct/mrpcs_meridians.h"
#include "struct/mrpcs_enchant_stone_info.h"
#include "struct/mrpcs_pk_record_info.h"
#include "struct/mrpcs_character_ranking_info.h"
#include "struct/mrpcs_adult_certification.h"
#include "struct/mps_dictionary_info.h"
#include "struct/mrpcs_avatar_info.h"
#include "struct/mps_item.h"
#include "struct/mps_list_dictionary_info.h"
#include "struct/mps_achieve_rate_info.h"
#include "struct/mps_cash_shop_buy_count.h"
#include "struct/mps_cart_item.h"
#include "struct/mps_cash_exchange_product.h"
#include "struct/mps_cash_package_product.h"
#include "struct/mps_revive.h"
#include "struct/mps_temp_reflection.h"

namespace mir3d
{
	class mrpc_test_game_login_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
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
	public:
		bool is_skill_open{};
	public:
		uint16_t server_index{};
	public:
		mrpce_server_type server_type{};
	public:
		uint16_t customzing_data{};

	public:
		mrpc_test_game_login_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::test_game_login_cs, tag)
		{
		}
		mrpc_test_game_login_cs() : RpcPacket(mpe_rpc_cmd::test_game_login_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &flag_zone);
			if (true == flag_zone)
			{
				if (nullptr != p_zone)
					protocol::SerializeType(pBuffer, p_zone);
				else
					protocol::SerializeType(pBuffer, &zone);
			}
			protocol::SerializeType(pBuffer, &is_skill_open);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &customzing_data);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_test_game_login_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		std::string username{};
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
		std::vector<mps_dictionary_info> dic_list{};
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
	public:
		int32_t security_level{};

	public:
		mrpc_test_game_login_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::test_game_login_sc, tag)
		{
		}
		mrpc_test_game_login_sc() : RpcPacket(mpe_rpc_cmd::test_game_login_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &username);
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
			protocol::SerializeType(pBuffer, &dic_list);
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
			protocol::SerializeType(pBuffer, &security_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
