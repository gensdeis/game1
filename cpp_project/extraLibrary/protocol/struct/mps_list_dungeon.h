#pragma once
#include <vector>
#include <string>
#include "mps_dungeon.h"

namespace mir3d
{
	class mps_list_dungeon 
	{
	public:
		std::vector<mps_dungeon> info{};

	public:
		mps_list_dungeon()
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
