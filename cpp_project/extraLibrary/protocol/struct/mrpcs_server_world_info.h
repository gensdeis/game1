#pragma once
#include <vector>
#include <string>
#include "mrpcs_server_group_info.h"

namespace mir3d
{
	class mrpcs_server_world_info 
	{
	public:
		int32_t world_gid{};
	public:
		std::vector<mrpcs_server_group_info> list{};

	public:
		mrpcs_server_world_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &world_gid);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
