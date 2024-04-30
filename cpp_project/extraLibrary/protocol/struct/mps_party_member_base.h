#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_party_member_base 
	{
	public:
		int64_t cuid{};
	public:
		int64_t puid{};
	public:
		int32_t slot{};	// //slot
	public:
		std::string nickname{};
	public:
		int32_t id{};	// //tableid
	public:
		int32_t level{};
	public:
		bool online{};
	public:
		int32_t zone_id{};
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		uint16_t channel_id{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_party_member_base()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &slot);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &online);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &channel_id);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
