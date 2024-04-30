#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_indun_play_count_request 
	{
	public:
		int32_t gid{};
	public:
		int32_t count{};

	public:
		mps_indun_play_count_request()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
