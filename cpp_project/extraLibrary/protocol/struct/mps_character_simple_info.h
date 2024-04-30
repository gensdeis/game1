#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_character_simple_info 
	{
	public:
		int64_t cuid{};
	public:
		int32_t level{};
	public:
		int32_t id{};
	public:
		std::string nickname{};
	public:
		std::string guildname{};
	public:
		bool is_friendreq_enable{};	// true:enable false:disable
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_character_simple_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &guildname);
			protocol::SerializeType(pBuffer, &is_friendreq_enable);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
