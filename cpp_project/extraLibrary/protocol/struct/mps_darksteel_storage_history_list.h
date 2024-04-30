#pragma once
#include <vector>
#include <string>
#include "mps_darksteel_storage_history.h"

namespace mir3d
{
	class mps_darksteel_storage_history_list 
	{
	public:
		std::vector<mps_darksteel_storage_history> list{};

	public:
		mps_darksteel_storage_history_list()
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
