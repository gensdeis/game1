#pragma once
#include <vector>
#include <string>
#include "mps_boss_governance_server_info_personal.h"

namespace mir3d
{
	class mps_boss_governance_server_info_personal_list 
	{
	public:
		std::vector<mps_boss_governance_server_info_personal> list{};	// 유저가 스테이킹한 서버들 정보

	public:
		mps_boss_governance_server_info_personal_list()
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
