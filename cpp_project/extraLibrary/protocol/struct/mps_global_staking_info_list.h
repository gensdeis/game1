#pragma once
#include <vector>
#include <string>
#include "mps_global_staking_info.h"

namespace mir3d
{
	class mps_global_staking_info_list 
	{
	public:
		std::vector<mps_global_staking_info> list{};
	public:
		std::string min_staking_amount{};	// 최소 스테이킹 수치

	public:
		mps_global_staking_info_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &min_staking_amount);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
