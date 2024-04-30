#pragma once
#include <vector>
#include <string>
#include "mps_occupationwar_schedule.h"

namespace mir3d
{
	class mps_occupationwar_schedule_info 
	{
	public:
		int64_t occupationwar_uid{};
	public:
		int64_t next_uid{};
	public:
		int32_t week_number{};
	public:
		std::vector<mps_occupationwar_schedule> list{};

	public:
		mps_occupationwar_schedule_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &occupationwar_uid);
			protocol::SerializeType(pBuffer, &next_uid);
			protocol::SerializeType(pBuffer, &week_number);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
