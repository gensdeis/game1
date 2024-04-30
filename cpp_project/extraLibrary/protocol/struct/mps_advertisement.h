#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_advertisement 
	{
	public:
		int32_t next_reset_time{};
	public:
		int32_t view_count{};

	public:
		mps_advertisement()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &next_reset_time);
			protocol::SerializeType(pBuffer, &view_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
