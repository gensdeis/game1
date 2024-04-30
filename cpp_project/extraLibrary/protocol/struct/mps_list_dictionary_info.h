#pragma once
#include <vector>
#include <string>
#include "mps_dictionary_info.h"

namespace mir3d
{
	class mps_list_dictionary_info 
	{
	public:
		int32_t category_id{};
	public:
		std::vector<mps_dictionary_info> list{};

	public:
		mps_list_dictionary_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &category_id);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
