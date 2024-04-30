#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_ally_simple_info 
	{
	public:
		int64_t ally_guid{};	// "동맹 길드 uid."
	public:
		std::string guild_name{};	// "문파이름"
	public:
		int64_t master_cuid{};	// "문주 cuid"
	public:
		int64_t sub_master_cuid{};	// "부문주 cuid"
	public:
		uint8_t slot{};	// "길드 슬롯번호"

	public:
		mps_guild_ally_simple_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &ally_guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &master_cuid);
			protocol::SerializeType(pBuffer, &sub_master_cuid);
			protocol::SerializeType(pBuffer, &slot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
