#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_character_stat 
	{
	public:
		int32_t hp{};
	public:
		int32_t mp{};

	public:
		mps_character_stat()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &hp);
			protocol::SerializeType(pBuffer, &mp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
