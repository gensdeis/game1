#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_temp_pet 
	{
	public:
		int64_t temp_uid{};
	public:
		int32_t id{};
	public:
		uint8_t count{};
	public:
		int32_t expire_time{};

	public:
		mps_temp_pet()
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
