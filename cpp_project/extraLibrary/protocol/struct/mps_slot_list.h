#pragma once
#include <vector>
#include <string>
#include "mps_slot.h"

namespace mir3d
{
	class mps_slot_list 
	{
	public:
		std::vector<mps_slot> list_slot{};

	public:
		mps_slot_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list_slot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
