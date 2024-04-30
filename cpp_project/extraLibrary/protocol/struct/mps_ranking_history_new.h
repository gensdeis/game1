#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_ranking_history_new 
	{
	public:
		mpe_ranking_type rank_type{};
	public:
		int32_t rank{};
	public:
		int64_t score{};
	public:
		int32_t profesion_level{};
	public:
		int32_t before_rank{};
	public:
		int64_t update_timestamp{};

	public:
		mps_ranking_history_new()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &rank_type);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &score);
			protocol::SerializeType(pBuffer, &profesion_level);
			protocol::SerializeType(pBuffer, &before_rank);
			protocol::SerializeType(pBuffer, &update_timestamp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
