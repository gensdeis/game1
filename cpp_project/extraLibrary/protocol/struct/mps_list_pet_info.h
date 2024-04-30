#pragma once
#include <vector>
#include <string>
#include "mps_pet_info.h"

namespace mir3d
{
	class mps_list_pet_info 
	{
	public:
		std::vector<mps_pet_info> info{};

	public:
		mps_list_pet_info()
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
