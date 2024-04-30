#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_mentor 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		int32_t id{};
	public:
		int32_t level{};
	public:
		int32_t power{};
	public:
		int64_t reg_date{};
	public:
		std::string guildname{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_mentor()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &power);
			protocol::SerializeType(pBuffer, &reg_date);
			protocol::SerializeType(pBuffer, &guildname);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
