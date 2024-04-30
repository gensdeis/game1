#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_schedule_info 	// 스케줄정보
	{
	public:
		uint8_t state{};
	public:
		uint8_t siege_type{};	// 공성타입
	public:
		int64_t start_time{};
	public:
		int64_t end_time{};

	public:
		mps_schedule_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &state);
			protocol::SerializeType(pBuffer, &siege_type);
			protocol::SerializeType(pBuffer, &start_time);
			protocol::SerializeType(pBuffer, &end_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
