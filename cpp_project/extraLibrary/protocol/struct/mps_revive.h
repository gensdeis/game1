#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_revive 
	{
	public:
		uint16_t id{};
	public:
		int64_t exp{};
	public:
		int32_t expire_time{};

	public:
		mps_revive()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &exp);
			protocol::SerializeType(pBuffer, &expire_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
