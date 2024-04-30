#pragma once
#include <vector>
#include <string>
#include "mrpcs_build_tool_dev_server_state.h"

namespace mir3d
{
	class mrpcs_build_tool_dev_server_group_state 
	{
	public:
		int32_t gid{};
	public:
		std::vector<mrpcs_build_tool_dev_server_state> list{};

	public:
		mrpcs_build_tool_dev_server_group_state()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
