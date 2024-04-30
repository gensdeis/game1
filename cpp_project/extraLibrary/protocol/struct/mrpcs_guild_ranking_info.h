#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_guild_ranking_info 
	{
	public:
		mpe_ranking_type ranking_type{};
	public:
		int64_t guid{};
	public:
		int64_t score{};
	public:
		int32_t current_rank{};
	public:
		std::string guild_name{};
	public:
		int64_t stored_exp{};
	public:
		int32_t town_house_level{};
	public:
		int32_t member_total_max_power{};
	public:
		bool have_castle{};
	public:
		int64_t master_cuid{};

	public:
		mrpcs_guild_ranking_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &ranking_type);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &score);
			protocol::SerializeType(pBuffer, &current_rank);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &stored_exp);
			protocol::SerializeType(pBuffer, &town_house_level);
			protocol::SerializeType(pBuffer, &member_total_max_power);
			protocol::SerializeType(pBuffer, &have_castle);
			protocol::SerializeType(pBuffer, &master_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
