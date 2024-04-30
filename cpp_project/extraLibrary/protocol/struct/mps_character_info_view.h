#pragma once
#include <vector>
#include <string>
#include "mps_character_stat.h"
#include "mps_item.h"
#include "mps_ranking_history.h"
#include "mps_title.h"
#include "mps_pet_info.h"
#include "mps_vehicle.h"
#include "mps_item.h"
#include "mps_ranking_history.h"
#include "mps_dic_stat.h"

namespace mir3d
{
	class mps_character_info_view 
	{
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		int32_t id{};
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
	public:
		int32_t level{};
	public:
		int32_t repute_point{};	// 평판
	public:
		std::vector<mps_item> list_equip{};
	public:
		int64_t puid{};
	public:
		int32_t power{};
	public:
		int32_t vehicle{};	// 장착중인 탈것
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		uint16_t customzing_data{};
	public:
		std::vector<mps_ranking_history> list_ranking{};
	public:
		uint8_t show_costume{};
	public:
		int32_t title{};	// 장착중인 칭호
	public:
		std::vector<mps_title> list_title{};	// 보유중인 칭호
	public:
		std::vector<mps_pet_info> list_pet_info{};	// 펫 목록
	public:
		std::vector<mps_vehicle> list_vehicle{};	// 탈것 목록
	public:
		std::vector<mps_item> list_equip_vehicle{};	// 탈것 장비목록
	public:
		std::vector<int32_t> list_guild_skill{};	// 길드 스킬
	private:
		bool flag_guild_ranking = false;
		mps_ranking_history guild_ranking;	// 길드 랭킹
		mps_ranking_history* p_guild_ranking = nullptr;
	public:
		bool has_guild_ranking() const
		{
			return flag_guild_ranking;
		}
		mps_ranking_history* alloc_guild_ranking()
		{
			flag_guild_ranking = true;
			return &guild_ranking;
		}
		const mps_ranking_history* get_guild_ranking() const
		{
			if (true == flag_guild_ranking)
			{
				if (nullptr == p_guild_ranking)
				{
					return &guild_ranking;
				}
				return p_guild_ranking;
			}
			return nullptr;
		}
		void set_guild_ranking(mps_ranking_history* in_guild_ranking)
		{
			if (nullptr == p_guild_ranking)
			{
				p_guild_ranking = in_guild_ranking;
				flag_guild_ranking = true;
			}
		}
	public:
		std::vector<mps_dic_stat> list_dic_stat{};	// 도감 스탯
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t reflection_id{};	// 화신 id

	public:
		mps_character_info_view()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &flag_stat);
			if (true == flag_stat)
			{
				if (nullptr != p_stat)
					protocol::SerializeType(pBuffer, p_stat);
				else
					protocol::SerializeType(pBuffer, &stat);
			}
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &repute_point);
			protocol::SerializeType(pBuffer, &list_equip);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &power);
			protocol::SerializeType(pBuffer, &vehicle);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &customzing_data);
			protocol::SerializeType(pBuffer, &list_ranking);
			protocol::SerializeType(pBuffer, &show_costume);
			protocol::SerializeType(pBuffer, &title);
			protocol::SerializeType(pBuffer, &list_title);
			protocol::SerializeType(pBuffer, &list_pet_info);
			protocol::SerializeType(pBuffer, &list_vehicle);
			protocol::SerializeType(pBuffer, &list_equip_vehicle);
			protocol::SerializeType(pBuffer, &list_guild_skill);
			protocol::SerializeType(pBuffer, &flag_guild_ranking);
			if (true == flag_guild_ranking)
			{
				if (nullptr != p_guild_ranking)
					protocol::SerializeType(pBuffer, p_guild_ranking);
				else
					protocol::SerializeType(pBuffer, &guild_ranking);
			}
			protocol::SerializeType(pBuffer, &list_dic_stat);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &reflection_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
