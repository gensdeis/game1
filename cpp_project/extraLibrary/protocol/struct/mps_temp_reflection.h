#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_temp_reflection 
	{
	public:
		int64_t temp_uid{};
	public:
		int32_t id{};	// reflection table id
	public:
		uint8_t count{};	// 재굴림 횟수
	public:
		int32_t expire_time{};	// 임시보관 완료시간

	public:
		mps_temp_reflection()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &temp_uid);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &expire_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
