#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_town_guild_tender 	// 장원 경매 길드 정보
	{
	public:
		int64_t guid{};
	public:
		int32_t tender_value{};	// 경매금액
	public:
		std::string name{};	// 길드이름
	public:
		std::string master_name{};	// 마스터이름

	public:
		mps_castle_town_guild_tender()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &tender_value);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &master_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
