#pragma once
#include <vector>
#include <string>
#include "mps_enchant_options.h"

namespace mir3d
{
	class mps_enchant_option_list 
	{
	public:
		std::vector<mps_enchant_options> info{};

	public:
		mps_enchant_option_list()
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
