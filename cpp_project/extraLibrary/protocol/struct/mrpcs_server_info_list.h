#pragma once
#include <vector>
#include <string>
#include "mrpcs_server_info.h"

namespace mir3d
{
	class mrpcs_server_info_list 
	{
	public:
		std::vector<mrpcs_server_info> list{};

	public:
		mrpcs_server_info_list()
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
