#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_character_advertisement 
	{
	public:
		int32_t next_reset_time{};
	public:
		int32_t exp_restore{};

	public:
		mps_character_advertisement()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &next_reset_time);
			protocol::SerializeType(pBuffer, &exp_restore);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
