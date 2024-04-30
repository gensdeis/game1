#pragma once
#include <vector>
#include <string>
#include "mrpcs_redis_rpcinfo.h"

namespace mir3d
{
	class mrpcs_deamontool_server_info 
	{
	public:
		int32_t gid{};
	public:
		std::string name{};
	public:
		std::vector<mrpcs_redis_rpcinfo> list{};

	public:
		mrpcs_deamontool_server_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
