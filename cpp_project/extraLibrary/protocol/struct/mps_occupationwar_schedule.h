#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_occupationwar_schedule 
	{
	public:
		mpe_occupationwar_schedule_type type{};
	public:
		int32_t date_time{};

	public:
		mps_occupationwar_schedule()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &date_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
