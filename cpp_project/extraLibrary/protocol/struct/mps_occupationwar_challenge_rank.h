#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_occupationwar_challenge_rank 
	{
	public:
		uint8_t rank{};
	public:
		int32_t gid{};

	public:
		mps_occupationwar_challenge_rank()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
