#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_around_user_info 
	{
	public:
		int64_t cuid{};
	public:
		int32_t id{};
	public:
		std::string nickname{};
	public:
		int32_t power{};
	public:
		int32_t level{};
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_around_user_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &power);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
