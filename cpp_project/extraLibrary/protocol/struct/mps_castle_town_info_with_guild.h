#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_town_info_with_guild 	// 장원 정보
	{
	public:
		int32_t town_id{};	// 장원아이디
	public:
		uint8_t town_grade{};	// 장원등급 / enum_table  /town_type
	public:
		int32_t table_id{};	// 테이블아이디
	public:
		std::string guild_name{};	// 길드이름
	public:
		std::string master_name{};	// 문파장이름
	public:
		bool is_enter{};	// 입주여부

	public:
		mps_castle_town_info_with_guild()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeType(pBuffer, &town_grade);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &master_name);
			protocol::SerializeType(pBuffer, &is_enter);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
