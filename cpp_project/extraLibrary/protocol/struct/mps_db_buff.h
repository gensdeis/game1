#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_db_buff 
	{
	public:
		int64_t uid{};
	public:
		int64_t time{};
	public:
		int32_t id{};

	public:
		mps_db_buff()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &time);
			protocol::SerializeType(pBuffer, &id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
