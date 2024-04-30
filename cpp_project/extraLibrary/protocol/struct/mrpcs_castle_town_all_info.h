#pragma once
#include <vector>
#include <string>
#include "mrpcs_castle_town_info.h"

namespace mir3d
{
	class mrpcs_castle_town_all_info 
	{
	public:
		std::vector<mrpcs_castle_town_info> info{};	// 장원 정보

	public:
		mrpcs_castle_town_all_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
