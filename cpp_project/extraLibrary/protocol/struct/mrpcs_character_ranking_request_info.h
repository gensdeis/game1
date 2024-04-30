#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_character_ranking_request_info 
	{
	public:
		mpe_ranking_type rank_type{};
	public:
		int64_t cuid{};
	public:
		int32_t gid{};

	public:
		mrpcs_character_ranking_request_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &rank_type);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
