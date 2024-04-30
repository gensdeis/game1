#pragma once
#include <vector>
#include <string>
#include "mrpcs_mentor_request.h"

namespace mir3d
{
	class mrpcs_list_mentor_request 
	{
	public:
		std::vector<mrpcs_mentor_request> info{};

	public:
		mrpcs_list_mentor_request()
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
