#pragma once
#include <vector>
#include <string>
#include "mps_ability_calc_option.h"

namespace mir3d
{
	class mps_dic_stat 
	{
	public:
		int32_t type{};	// 도감 타입
	public:
		std::vector<mps_ability_calc_option> list_stat{};

	public:
		mps_dic_stat()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &list_stat);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
