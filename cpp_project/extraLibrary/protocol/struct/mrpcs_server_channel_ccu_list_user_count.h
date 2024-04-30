﻿#pragma once
#include <vector>
#include <string>
#include "mrpcs_channel_ccu_info.h"

namespace mir3d
{
	class mrpcs_server_channel_ccu_list_user_count 
	{
	public:
		int32_t gid{};
	public:
		std::string name{};
	public:
		std::vector<mrpcs_channel_ccu_info> list_user_count{};

	public:
		mrpcs_server_channel_ccu_list_user_count()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &list_user_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
