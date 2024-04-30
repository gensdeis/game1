#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_arena_battle_ranking_info 
	{
	public:
		int64_t cuid{};
	public:
		int32_t id{};
	public:
		int32_t level{};
	public:
		std::string nickname{};
	public:
		std::string guildname{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t rank{};
	public:
		int32_t score{};
	public:
		int32_t gid{};
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_arena_battle_ranking_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &guildname);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &score);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
