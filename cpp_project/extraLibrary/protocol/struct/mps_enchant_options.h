#pragma once
#include <vector>
#include <string>
#include "mps_enchant_option_result.h"

namespace mir3d
{
	class mps_enchant_options 
	{
	public:
		std::vector<mps_enchant_option_result> list{};

	public:
		mps_enchant_options()
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
