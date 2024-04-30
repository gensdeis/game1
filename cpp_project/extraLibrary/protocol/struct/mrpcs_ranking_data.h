#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_ranking_data 
	{
	public:
		mpe_ranking_type rank_type{};
	public:
		int64_t uid{};
	public:
		int64_t score{};
	public:
		int32_t level_point{};
	public:
		int64_t exp_point{};
	public:
		int32_t profesion_level{};
	public:
		int32_t current_rank{};

	public:
		mrpcs_ranking_data()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &rank_type);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &score);
			protocol::SerializeType(pBuffer, &level_point);
			protocol::SerializeType(pBuffer, &exp_point);
			protocol::SerializeType(pBuffer, &profesion_level);
			protocol::SerializeType(pBuffer, &current_rank);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
