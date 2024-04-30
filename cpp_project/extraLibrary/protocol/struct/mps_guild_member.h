#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_member 
	{
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		int32_t class_id{};
	public:
		int32_t level{};
	public:
		mpe_guild_member_grade grade{};
	public:
		bool online{};
	public:
		int64_t last_online_time{};
	public:
		int64_t join_time{};
	public:
		int32_t contribution_weekly_point{};
	public:
		int32_t contribution_accumulated_point{};
	public:
		int32_t last_donation_count_reset_time{};
	public:
		uint8_t donation_count{};
	public:
		uint8_t blackiron_donation_count{};
	public:
		uint8_t goldingot_donation_count{};
	public:
		uint8_t item_donation_count{};
	public:
		uint8_t get_item_request_count_storage_share{};
	public:
		uint8_t get_item_count_storage_supply{};
	public:
		mpe_quest_state master_order_quest_state{};
	public:
		int32_t master_order_quest_object_count{};
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_guild_member()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &class_id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeEnum(pBuffer, &grade);
			protocol::SerializeType(pBuffer, &online);
			protocol::SerializeType(pBuffer, &last_online_time);
			protocol::SerializeType(pBuffer, &join_time);
			protocol::SerializeType(pBuffer, &contribution_weekly_point);
			protocol::SerializeType(pBuffer, &contribution_accumulated_point);
			protocol::SerializeType(pBuffer, &last_donation_count_reset_time);
			protocol::SerializeType(pBuffer, &donation_count);
			protocol::SerializeType(pBuffer, &blackiron_donation_count);
			protocol::SerializeType(pBuffer, &goldingot_donation_count);
			protocol::SerializeType(pBuffer, &item_donation_count);
			protocol::SerializeType(pBuffer, &get_item_request_count_storage_share);
			protocol::SerializeType(pBuffer, &get_item_count_storage_supply);
			protocol::SerializeEnum(pBuffer, &master_order_quest_state);
			protocol::SerializeType(pBuffer, &master_order_quest_object_count);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
