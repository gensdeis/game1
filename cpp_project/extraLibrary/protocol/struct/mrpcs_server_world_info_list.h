#pragma once
#include <vector>
#include <string>
#include "mrpcs_server_world_info.h"

namespace mir3d
{
	class mrpcs_server_world_info_list 
	{
	public:
		std::vector<mrpcs_server_world_info> info{};

	public:
		mrpcs_server_world_info_list()
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
