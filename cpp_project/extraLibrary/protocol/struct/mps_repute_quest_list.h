#pragma once
#include <vector>
#include <string>
#include "mps_repute_quest.h"

namespace mir3d
{
	class mps_repute_quest_list 
	{
	public:
		std::vector<mps_repute_quest> list_repute_quest{};

	public:
		mps_repute_quest_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list_repute_quest);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
