#pragma once
#include <vector>
#include <string>
#include "mps_ability_value.h"

namespace mir3d
{
	class mps_stat_update 
	{
	public:
		int64_t object_uid{};
	public:
		int64_t buff_uid{};
	public:
		std::vector<mps_ability_value> update_list{};

	public:
		mps_stat_update()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &object_uid);
			protocol::SerializeType(pBuffer, &buff_uid);
			protocol::SerializeType(pBuffer, &update_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
