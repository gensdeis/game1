#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_shipwar_character 
	{
	public:
		std::string guild_name{};
	public:
		std::string nickname{};
	public:
		int32_t id{};	// 클래스
	public:
		int32_t add_score{};
	public:
		int32_t guild_add_score{};
	public:
		std::vector<uint8_t> guild_mark{};	// 문파 문장
	public:
		int32_t gid{};
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_shipwar_character()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &add_score);
			protocol::SerializeType(pBuffer, &guild_add_score);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
