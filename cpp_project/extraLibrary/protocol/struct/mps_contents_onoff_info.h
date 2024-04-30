#pragma once
#include <vector>
#include <string>
#include "mps_contents_onoff_data.h"

namespace mir3d
{
	class mps_contents_onoff_info 
	{
	public:
		mpe_contents_onoff_type contents_type{};
	public:
		std::vector<mps_contents_onoff_data> contents_onoff_list{};

	public:
		mps_contents_onoff_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &contents_type);
			protocol::SerializeType(pBuffer, &contents_onoff_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
