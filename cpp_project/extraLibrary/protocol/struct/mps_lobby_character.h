#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_lobby_character 
	{
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		int32_t level{};
	public:
		int32_t id{};
	public:
		int32_t zone_id{};
	public:
		int32_t power{};
	public:
		int32_t lasttime{};
	public:
		int32_t equip_0{};
	public:
		int32_t equip_1{};
	public:
		int32_t equip_2{};
	public:
		uint16_t customzing_data{};
	public:
		uint8_t is_first_story{};	// 0 : first 
	public:
		int64_t auto_battle_free_time{};
	public:
		int64_t auto_battle_pay_time{};
	public:
		bool auto_battle_onoff{};
	public:
		int64_t auto_battle_login_time{};
	public:
		int64_t auto_battle_logout_time{};
	public:
		uint8_t summon_skill_level{};
	public:
		int32_t delete_date{};
	public:
		int32_t reflection_id{};
	public:
		int32_t old_gid{};
	public:
		int64_t server_relocation_time{};	// 서버 이전 쿨타임
	public:
		uint8_t is_delete{};
	public:
		int32_t server_relocate_target_gid{};
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_lobby_character()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &power);
			protocol::SerializeType(pBuffer, &lasttime);
			protocol::SerializeType(pBuffer, &equip_0);
			protocol::SerializeType(pBuffer, &equip_1);
			protocol::SerializeType(pBuffer, &equip_2);
			protocol::SerializeType(pBuffer, &customzing_data);
			protocol::SerializeType(pBuffer, &is_first_story);
			protocol::SerializeType(pBuffer, &auto_battle_free_time);
			protocol::SerializeType(pBuffer, &auto_battle_pay_time);
			protocol::SerializeType(pBuffer, &auto_battle_onoff);
			protocol::SerializeType(pBuffer, &auto_battle_login_time);
			protocol::SerializeType(pBuffer, &auto_battle_logout_time);
			protocol::SerializeType(pBuffer, &summon_skill_level);
			protocol::SerializeType(pBuffer, &delete_date);
			protocol::SerializeType(pBuffer, &reflection_id);
			protocol::SerializeType(pBuffer, &old_gid);
			protocol::SerializeType(pBuffer, &server_relocation_time);
			protocol::SerializeType(pBuffer, &is_delete);
			protocol::SerializeType(pBuffer, &server_relocate_target_gid);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
