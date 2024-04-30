#pragma once
#include <vector>
#include <string>
#include "mps_boss_governance_server_info_total.h"

namespace mir3d
{
	class mps_boss_governance_server_info_list 
	{
	public:
		std::vector<mps_boss_governance_server_info_total> list{};

	public:
		mps_boss_governance_server_info_list()
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
