#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_war 	// 문파 전쟁 정보
	{
	public:
		int64_t enemy_guid{};	// 상대문파ID
	public:
		std::string enemy_guild_name{};	// 상대문파명
	public:
		std::string enemy_guild_master_name{};	// 상대문주명
	public:
		mpe_guild_war_state state{};	// 전쟁 상태
	public:
		int32_t our_reject_count{};	// 아군이 항복거절한 횟수
	public:
		int32_t enemy_reject_count{};	// 적군이 항복거절한 횟수
	public:
		int64_t last_negotiation_guid{};	// 마지막 협상시도한 문파ID
	public:
		int32_t last_negotiation_gold{};	// 마지막 협상시도 금액
	public:
		int64_t negotiation_expire_time{};	// 항복 자동거절 시간
	public:
		int64_t next_available_start_time{};	// 다음 전쟁 재시작 가능시간
	public:
		std::vector<uint8_t> enemy_guild_mark{};	// 상대문파 문장
	public:
		int64_t war_start_time{};	// 전쟁시작시간(utc0 초)

	public:
		mps_guild_war()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &enemy_guid);
			protocol::SerializeType(pBuffer, &enemy_guild_name);
			protocol::SerializeType(pBuffer, &enemy_guild_master_name);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &our_reject_count);
			protocol::SerializeType(pBuffer, &enemy_reject_count);
			protocol::SerializeType(pBuffer, &last_negotiation_guid);
			protocol::SerializeType(pBuffer, &last_negotiation_gold);
			protocol::SerializeType(pBuffer, &negotiation_expire_time);
			protocol::SerializeType(pBuffer, &next_available_start_time);
			protocol::SerializeType(pBuffer, &enemy_guild_mark);
			protocol::SerializeType(pBuffer, &war_start_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
