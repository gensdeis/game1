#pragma once
#include <vector>
#include <string>
#include "mps_token_history.h"

namespace mir3d
{
	class mps_token_history_info 
	{
	public:
		std::vector<mps_token_history> list{};

	public:
		mps_token_history_info()
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
