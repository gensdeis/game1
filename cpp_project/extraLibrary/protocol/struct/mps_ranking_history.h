#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_ranking_history 
	{
	public:
		mpe_ranking_type rank_type{};
	public:
		int32_t rank{};
	public:
		int64_t score{};
	public:
		int32_t before_rank{};

	public:
		mps_ranking_history()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &rank_type);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &score);
			protocol::SerializeType(pBuffer, &before_rank);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
