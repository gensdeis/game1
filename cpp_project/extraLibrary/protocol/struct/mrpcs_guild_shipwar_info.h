#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_guild_shipwar_info 
	{
	public:
		int64_t guid{};
	public:
		int32_t rank{};
	public:
		std::string guild_name{};
	public:
		std::vector<uint8_t> guild_mark{};	// 문파 문장
	public:
		int32_t gid{};
	public:
		int32_t rank_score{};

	public:
		mrpcs_guild_shipwar_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &rank_score);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
