#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_character_situation 
	{
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		int32_t tid{};
	public:
		int32_t level{};
	public:
		mpe_guild_shipwar_character_state state{};
	public:
		int32_t kill_count{};
	public:
		int32_t dead_count{};
	public:
		int32_t contribution_degree{};
	public:
		int32_t destroy_tower_count{};
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_character_situation()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &kill_count);
			protocol::SerializeType(pBuffer, &dead_count);
			protocol::SerializeType(pBuffer, &contribution_degree);
			protocol::SerializeType(pBuffer, &destroy_tower_count);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
