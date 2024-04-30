﻿#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_boss_governance_server_info_personal 
	{
	public:
		int32_t gid{};
	public:
		int32_t sector_id{};
	public:
		std::string amount{};

	public:
		mps_boss_governance_server_info_personal()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &sector_id);
			protocol::SerializeType(pBuffer, &amount);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
