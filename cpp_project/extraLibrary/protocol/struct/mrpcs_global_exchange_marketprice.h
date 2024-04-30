#pragma once
#include <vector>
#include <string>
#include "mrpcs_global_exchange_price.h"

namespace mir3d
{
	class mrpcs_global_exchange_marketprice 
	{
	public:
		int32_t updatetime{};
	public:
		std::vector<mrpcs_global_exchange_price> list{};

	public:
		mrpcs_global_exchange_marketprice()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &updatetime);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
