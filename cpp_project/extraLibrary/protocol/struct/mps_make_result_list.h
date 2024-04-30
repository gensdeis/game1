#pragma once
#include <vector>
#include <string>
#include "mps_make_result.h"

namespace mir3d
{
	class mps_make_result_list 
	{
	public:
		std::vector<mps_make_result> list_result{};

	public:
		mps_make_result_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list_result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
