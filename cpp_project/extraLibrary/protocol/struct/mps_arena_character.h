#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_arena_character 
	{
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		int32_t id{};	// 클래스
	public:
		int32_t kill_count{};
	public:
		int32_t death_count{};
	public:
		uint8_t team{};
	public:
		int64_t damage{};
	public:
		int64_t suffer_damage{};
	public:
		uint8_t win_lose{};
	public:
		int32_t add_score{};
	public:
		bool is_mvp{};
	public:
		int32_t gid{};
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_arena_character()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &kill_count);
			protocol::SerializeType(pBuffer, &death_count);
			protocol::SerializeType(pBuffer, &team);
			protocol::SerializeType(pBuffer, &damage);
			protocol::SerializeType(pBuffer, &suffer_damage);
			protocol::SerializeType(pBuffer, &win_lose);
			protocol::SerializeType(pBuffer, &add_score);
			protocol::SerializeType(pBuffer, &is_mvp);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
