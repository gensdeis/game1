#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_occupationwar_guild_info 
	{
	public:
		int64_t guid{};
	public:
		mpe_occupationwar_map_type map_type{};
	public:
		int32_t week_number{};
	public:
		std::string guild_name{};	// 문파 이름
	public:
		uint8_t master_class{};
	public:
		uint16_t master_level{};	// 문주 level
	public:
		std::string master_name{};	// 문파장 이름
	public:
		std::vector<uint8_t> guild_mark{};	// 문파 문양
	public:
		int64_t darksteel_amount{};	// 흑철창고 흑철량
	public:
		int64_t darksteel_daily{};	// 일일 채굴량
	public:
		int64_t darksteel_tax{};	// 흑철 세금(어제)
	public:
		int64_t governance_tax{};	// 거버넌스 세금(어제)
	public:
		int32_t master_expert_level{};	// "문주전직레벨"

	public:
		mps_occupationwar_guild_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &map_type);
			protocol::SerializeType(pBuffer, &week_number);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &master_class);
			protocol::SerializeType(pBuffer, &master_level);
			protocol::SerializeType(pBuffer, &master_name);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &darksteel_amount);
			protocol::SerializeType(pBuffer, &darksteel_daily);
			protocol::SerializeType(pBuffer, &darksteel_tax);
			protocol::SerializeType(pBuffer, &governance_tax);
			protocol::SerializeType(pBuffer, &master_expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
