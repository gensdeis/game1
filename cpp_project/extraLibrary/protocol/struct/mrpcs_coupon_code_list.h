#pragma once
#include <vector>
#include <string>
#include "mrpcs_coupon_code.h"

namespace mir3d
{
	class mrpcs_coupon_code_list 
	{
	public:
		std::vector<mrpcs_coupon_code> info{};

	public:
		mrpcs_coupon_code_list()
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
