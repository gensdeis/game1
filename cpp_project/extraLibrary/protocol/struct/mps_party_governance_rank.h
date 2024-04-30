#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_party_governance_rank 
	{
	public:
		int64_t cuid{};
	public:
		int32_t rank{};
	public:
		int32_t id{};
	public:
		int32_t level{};
	public:
		int32_t gid{};
	public:
		std::string amount{};
	public:
		std::string nickname{};
	public:
		std::string guildname{};
	public:
		std::vector<uint8_t> guild_mark{};	// 문파 문장
	public:
		bool on_off{};	// 혜택여부(false:미혜택/true:혜택)
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_party_governance_rank()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &amount);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &guildname);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &on_off);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
