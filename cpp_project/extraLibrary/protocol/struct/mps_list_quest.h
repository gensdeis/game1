#pragma once
#include <vector>
#include <string>
#include "mps_quest.h"

namespace mir3d
{
	class mps_list_quest 
	{
	public:
		std::vector<mps_quest> list{};

	public:
		mps_list_quest()
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
