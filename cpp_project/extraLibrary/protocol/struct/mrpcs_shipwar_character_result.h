#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_shipwar_character_result 
	{
	public:
		int64_t guid{};
	public:
		int64_t indun_uid{};
	public:
		int64_t cuid{};
	public:
		std::string guild_name{};
	public:
		std::string nickname{};
	public:
		int32_t tid{};
	public:
		int32_t add_score{};
	public:
		int32_t guild_add_score{};
	public:
		int32_t season_round{};
	public:
		uint8_t win_lose{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t gid{};
	public:
		int32_t expert_level{};	// 전직 레벨

	public:
		mrpcs_shipwar_character_result()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &add_score);
			protocol::SerializeType(pBuffer, &guild_add_score);
			protocol::SerializeType(pBuffer, &season_round);
			protocol::SerializeType(pBuffer, &win_lose);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
