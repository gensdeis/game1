#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_occupationwar_challenge_guild_info 
	{
	public:
		mpe_occupationwar_map_type map_type{};
	public:
		int64_t guid{};
	public:
		std::string guid_name{};
	public:
		std::string master_name{};
	public:
		uint8_t master_class{};
	public:
		uint16_t master_level{};
	public:
		int32_t guild_rank{};	// 문파 랭킹
	public:
		std::vector<uint8_t> guild_mark{};	// 문파 문양
	public:
		int32_t master_expert_level{};	// "문주전직레벨"

	public:
		mps_occupationwar_challenge_guild_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &map_type);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guid_name);
			protocol::SerializeType(pBuffer, &master_name);
			protocol::SerializeType(pBuffer, &master_class);
			protocol::SerializeType(pBuffer, &master_level);
			protocol::SerializeType(pBuffer, &guild_rank);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &master_expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
