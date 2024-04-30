#pragma once
#include <vector>
#include <string>
#include "mps_contents_onoff.h"

namespace mir3d
{
	class mps_contents_onoff_list 
	{
	public:
		mpe_contents_onoff_type type{};
	public:
		std::vector<mps_contents_onoff> list{};

	public:
		mps_contents_onoff_list()
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
