#pragma once
#include <vector>
#include <string>
#include "mrpcs_redis_czone.h"

namespace mir3d
{
	class mrpcs_redis_channel_zone_list 
	{
	public:
		std::vector<mrpcs_redis_czone> list{};

	public:
		mrpcs_redis_channel_zone_list()
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
