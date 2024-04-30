#pragma once
#include <vector>
#include <string>
#include "mps_title.h"

namespace mir3d
{
	class mrpcs_list_title 
	{
	public:
		std::vector<mps_title> list{};

	public:
		mrpcs_list_title()
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
