#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_league_rank 
	{
	public:
		int64_t guid{};
	public:
		std::string name{};
	public:
		uint16_t league{};
	public:
		int32_t score{};
	public:
		int32_t rank{};
	public:
		std::string master_name{};
	public:
		int32_t master_level{};
	public:
		uint16_t master_class{};
	public:
		std::vector<uint8_t> guild_mark{};	// 문파 문장
	public:
		int32_t win_count{};
	public:
		int32_t lose_count{};
	public:
		int32_t draw_count{};
	public:
		int32_t gid{};

	public:
		mps_guild_league_rank()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &league);
			protocol::SerializeType(pBuffer, &score);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &master_name);
			protocol::SerializeType(pBuffer, &master_level);
			protocol::SerializeType(pBuffer, &master_class);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &win_count);
			protocol::SerializeType(pBuffer, &lose_count);
			protocol::SerializeType(pBuffer, &draw_count);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
