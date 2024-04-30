#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_secretvalley_owner_info 
	{
	public:
		uint8_t secretvalley_type{};	// enum SecretValley
	public:
		std::vector<uint8_t> guild_mark{};	// 점령 문파 문장
	public:
		std::string guild_name{};	// 점령 문파 이름
	public:
		int32_t guild_master_tid{};	// 점령 문파 문주 직업
	public:
		std::string guild_master_name{};	// 점령 문파 문주
	public:
		int64_t guild_uid{};	// 점령 문파uid
	public:
		int32_t occupation_count{};	// 점령 횟수
	public:
		int32_t blackiron_daily_count{};	// 일일 채굴량
	public:
		int32_t blackiron_sell_count{};	// 판매 량
	public:
		int32_t blackiron_sell_regist_next_time{};	// 흑철 판매 등록 가능시간
	public:
		std::vector<int64_t> list_ally_guid{};	// "동맹길드 guid 목록"

	public:
		mps_secretvalley_owner_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &secretvalley_type);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &guild_master_tid);
			protocol::SerializeType(pBuffer, &guild_master_name);
			protocol::SerializeType(pBuffer, &guild_uid);
			protocol::SerializeType(pBuffer, &occupation_count);
			protocol::SerializeType(pBuffer, &blackiron_daily_count);
			protocol::SerializeType(pBuffer, &blackiron_sell_count);
			protocol::SerializeType(pBuffer, &blackiron_sell_regist_next_time);
			protocol::SerializeType(pBuffer, &list_ally_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
