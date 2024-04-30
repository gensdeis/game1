#pragma once
#include <vector>
#include <string>
#include "mrpcs_build_tool_dev_server.h"

namespace mir3d
{
	class mrpcs_build_tool_server_info 
	{
	public:
		int32_t gid{};
	public:
		std::string name{};
	public:
		std::string build_path{};
	public:
		std::string publish_path{};
	public:
		std::string master_svn_path{};
	public:
		std::vector<mrpcs_build_tool_dev_server> list_server{};

	public:
		mrpcs_build_tool_server_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &build_path);
			protocol::SerializeType(pBuffer, &publish_path);
			protocol::SerializeType(pBuffer, &master_svn_path);
			protocol::SerializeType(pBuffer, &list_server);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
