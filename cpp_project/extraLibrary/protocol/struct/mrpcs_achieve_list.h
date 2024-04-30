#pragma once
#include <vector>
#include <string>
#include "mps_achieve_info.h"

namespace mir3d
{
	class mrpcs_achieve_list 
	{
	public:
		std::vector<mps_achieve_info> list{};

	public:
		mrpcs_achieve_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
