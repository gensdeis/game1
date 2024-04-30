#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_town_log 
	{
	public:
		uint8_t log_num{};
	public:
		uint8_t log_param_0{};
	public:
		uint8_t log_param_1{};
	public:
		int32_t reg_time{};

	public:
		mps_castle_town_log()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &log_num);
			protocol::SerializeType(pBuffer, &log_param_0);
			protocol::SerializeType(pBuffer, &log_param_1);
			protocol::SerializeType(pBuffer, &reg_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
