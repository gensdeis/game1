#pragma once
#include <vector>
#include <string>
#include "mrpcs_random_coupon.h"

namespace mir3d
{
	class mrpcs_random_coupon_use 
	{
	public:
		int32_t seq{};
	public:
		std::vector<mrpcs_random_coupon> info{};

	public:
		mrpcs_random_coupon_use()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &seq);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
