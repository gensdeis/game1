#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_other_guild_info 
	{
	public:
		int64_t guid{};
	public:
		std::vector<uint8_t> guild_mark{};	// 문파 문양
	public:
		std::string guild_name{};
	public:
		std::string introduction{};
	public:
		std::string notice{};
	public:
		int32_t level{};
	public:
		mpe_guild_join_type join_type{};
	public:
		int32_t join_level{};
	public:
		int64_t master_cuid{};
	public:
		int64_t submaster_cuid{};
	public:
		std::string master_nickname{};
	public:
		int32_t current_member_count{};
	public:
		int32_t max_member_count{};
	public:
		int32_t current_elder_count{};
	public:
		int32_t max_elder_count{};
	public:
		int32_t guild_power{};	// "길드전투력 (문원전투력합)"
	public:
		int32_t war_count{};	// "전쟁선포 수"
	public:
		std::vector<int32_t> skill_list{};	// "길드스킬목록"
	public:
		int64_t create_time{};
	public:
		int64_t notice_update_time{};
	public:
		int32_t ranking{};	// "문파순위"
	public:
		int64_t rank_socre{};	// "문파순위점수"
	public:
		int32_t guild_exp{};	// "문파경험치"

	public:
		mps_other_guild_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &introduction);
			protocol::SerializeType(pBuffer, &notice);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeEnum(pBuffer, &join_type);
			protocol::SerializeType(pBuffer, &join_level);
			protocol::SerializeType(pBuffer, &master_cuid);
			protocol::SerializeType(pBuffer, &submaster_cuid);
			protocol::SerializeType(pBuffer, &master_nickname);
			protocol::SerializeType(pBuffer, &current_member_count);
			protocol::SerializeType(pBuffer, &max_member_count);
			protocol::SerializeType(pBuffer, &current_elder_count);
			protocol::SerializeType(pBuffer, &max_elder_count);
			protocol::SerializeType(pBuffer, &guild_power);
			protocol::SerializeType(pBuffer, &war_count);
			protocol::SerializeType(pBuffer, &skill_list);
			protocol::SerializeType(pBuffer, &create_time);
			protocol::SerializeType(pBuffer, &notice_update_time);
			protocol::SerializeType(pBuffer, &ranking);
			protocol::SerializeType(pBuffer, &rank_socre);
			protocol::SerializeType(pBuffer, &guild_exp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
