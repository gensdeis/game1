#pragma once
#include <vector>
#include <string>
#include "mrpcs_stoneslotopen_probalility.h"

namespace mir3d
{
	class mrpcs_stoneslotopen_probalility_info 
	{
	public:
		uint8_t type{};
	public:
		uint8_t slot{};
	public:
		std::vector<mrpcs_stoneslotopen_probalility> list{};

	public:
		mrpcs_stoneslotopen_probalility_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &slot);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
