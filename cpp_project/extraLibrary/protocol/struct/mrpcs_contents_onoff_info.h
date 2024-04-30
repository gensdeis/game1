#pragma once
#include <vector>
#include <string>
#include "mrpcs_contents_onoff.h"

namespace mir3d
{
	class mrpcs_contents_onoff_info 
	{
	public:
		mpe_contents_onoff_type type{};
	public:
		std::vector<mrpcs_contents_onoff> list{};

	public:
		mrpcs_contents_onoff_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
