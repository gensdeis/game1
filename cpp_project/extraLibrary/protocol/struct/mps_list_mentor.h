#pragma once
#include <vector>
#include <string>
#include "mps_mentor.h"

namespace mir3d
{
	class mps_list_mentor 
	{
	public:
		std::vector<mps_mentor> info{};

	public:
		mps_list_mentor()
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
