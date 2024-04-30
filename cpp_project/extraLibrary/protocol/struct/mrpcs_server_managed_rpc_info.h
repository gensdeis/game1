#pragma once
#include <vector>
#include <string>
#include "mrpcs_managed_rpc_info.h"

namespace mir3d
{
	class mrpcs_server_managed_rpc_info 
	{
	public:
		std::string name{};
	public:
		std::vector<mrpcs_managed_rpc_info> info{};

	public:
		mrpcs_server_managed_rpc_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
