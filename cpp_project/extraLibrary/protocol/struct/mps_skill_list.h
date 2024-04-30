#pragma once
#include <vector>
#include <string>
#include "mps_skill.h"

namespace mir3d
{
	class mps_skill_list 
	{
	public:
		std::vector<mps_skill> list{};

	public:
		mps_skill_list()
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
