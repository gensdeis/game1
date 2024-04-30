#pragma once
#include <vector>
#include <string>
#include "mrpcs_profesion_ranking_info.h"

namespace mir3d
{
	class mrpcs_list_profesion_ranking 
	{
	public:
		std::vector<mrpcs_profesion_ranking_info> list_ranking{};

	public:
		mrpcs_list_profesion_ranking()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list_ranking);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
