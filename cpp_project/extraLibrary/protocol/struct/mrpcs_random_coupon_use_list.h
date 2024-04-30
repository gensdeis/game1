#pragma once
#include <vector>
#include <string>
#include "mrpcs_random_coupon_use.h"

namespace mir3d
{
	class mrpcs_random_coupon_use_list 
	{
	public:
		std::vector<mrpcs_random_coupon_use> info{};

	public:
		mrpcs_random_coupon_use_list()
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
