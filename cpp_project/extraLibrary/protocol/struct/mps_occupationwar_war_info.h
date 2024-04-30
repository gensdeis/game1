#pragma once
#include <vector>
#include <string>
#include "mps_occupationwar_challenge_rank.h"

namespace mir3d
{
	class mps_occupationwar_war_info 
	{
	public:
		int64_t occupationwar_uid{};
	public:
		int32_t week_number{};
	public:
		std::vector<mps_occupationwar_challenge_rank> list_server{};

	public:
		mps_occupationwar_war_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &occupationwar_uid);
			protocol::SerializeType(pBuffer, &week_number);
			protocol::SerializeType(pBuffer, &list_server);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
