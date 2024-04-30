#pragma once
#include <vector>
#include <string>
#include "mps_seasonpass_challenge.h"

namespace mir3d
{
	class mrpcs_list_seasonpass_challenge 
	{
	public:
		std::vector<mps_seasonpass_challenge> list{};

	public:
		mrpcs_list_seasonpass_challenge()
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
