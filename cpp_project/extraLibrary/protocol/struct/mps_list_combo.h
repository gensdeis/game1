#pragma once
#include <vector>
#include <string>
#include "mps_combo_info.h"

namespace mir3d
{
	class mps_list_combo 
	{
	public:
		std::vector<mps_combo_info> info{};

	public:
		mps_list_combo()
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
