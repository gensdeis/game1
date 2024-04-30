#pragma once
#include <vector>
#include <string>
#include "mps_comm_equip_list.h"

namespace mir3d
{
	class mrpcs_comm_character 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		mrpce_server_type server_type{};
	public:
		int32_t server_index{};
	public:
		int32_t level{};
	public:
		int32_t zone_id{};
	private:
		bool flag_equip_list = false;
		mps_comm_equip_list equip_list;
		mps_comm_equip_list* p_equip_list = nullptr;
	public:
		bool has_equip_list() const
		{
			return flag_equip_list;
		}
		mps_comm_equip_list* alloc_equip_list()
		{
			flag_equip_list = true;
			return &equip_list;
		}
		const mps_comm_equip_list* get_equip_list() const
		{
			if (true == flag_equip_list)
			{
				if (nullptr == p_equip_list)
				{
					return &equip_list;
				}
				return p_equip_list;
			}
			return nullptr;
		}
		void set_equip_list(mps_comm_equip_list* in_equip_list)
		{
			if (nullptr == p_equip_list)
			{
				p_equip_list = in_equip_list;
				flag_equip_list = true;
			}
		}
	public:
		int32_t power{};
	public:
		int32_t max_power{};
	public:
		int64_t puid{};
	public:
		bool connect{};
	public:
		int64_t last_online_time{};
	public:
		std::string nickname{};
	public:
		int32_t id{};
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		float pos_x{};
	public:
		float pos_y{};
	public:
		float pos_z{};
	public:
		uint16_t channel_id{};
	public:
		mrpce_character_delete_progress delete_progress{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t create_date{};
	public:
		mpe_guild_member_grade guild_grade{};
	public:
		int64_t mentor_next_available_join_time{};
	public:
		mrpce_server_type prev_server_type{};
	public:
		int32_t prev_server_index{};
	public:
		int32_t prev_zone_id{};
	public:
		float prev_pos_x{};
	public:
		float prev_pos_y{};
	public:
		float prev_pos_z{};
	public:
		uint16_t prev_channel_id{};
	public:
		int32_t expert_level{};	// 전직 레벨

	public:
		mrpcs_comm_character()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &flag_equip_list);
			if (true == flag_equip_list)
			{
				if (nullptr != p_equip_list)
					protocol::SerializeType(pBuffer, p_equip_list);
				else
					protocol::SerializeType(pBuffer, &equip_list);
			}
			protocol::SerializeType(pBuffer, &power);
			protocol::SerializeType(pBuffer, &max_power);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &connect);
			protocol::SerializeType(pBuffer, &last_online_time);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &pos_x);
			protocol::SerializeType(pBuffer, &pos_y);
			protocol::SerializeType(pBuffer, &pos_z);
			protocol::SerializeType(pBuffer, &channel_id);
			protocol::SerializeEnum(pBuffer, &delete_progress);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &create_date);
			protocol::SerializeEnum(pBuffer, &guild_grade);
			protocol::SerializeType(pBuffer, &mentor_next_available_join_time);
			protocol::SerializeEnum(pBuffer, &prev_server_type);
			protocol::SerializeType(pBuffer, &prev_server_index);
			protocol::SerializeType(pBuffer, &prev_zone_id);
			protocol::SerializeType(pBuffer, &prev_pos_x);
			protocol::SerializeType(pBuffer, &prev_pos_y);
			protocol::SerializeType(pBuffer, &prev_pos_z);
			protocol::SerializeType(pBuffer, &prev_channel_id);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
