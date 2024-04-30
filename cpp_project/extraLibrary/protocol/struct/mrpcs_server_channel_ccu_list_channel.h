#pragma once
#include <vector>
#include <string>
#include "mrpcs_server_info.h"

namespace mir3d
{
	class mrpcs_server_channel_ccu_list_channel 
	{
	public:
		int32_t gid{};
	public:
		std::string name{};
	public:
		std::vector<mrpcs_server_info> list_channel{};

	public:
		mrpcs_server_channel_ccu_list_channel()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &list_channel);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
