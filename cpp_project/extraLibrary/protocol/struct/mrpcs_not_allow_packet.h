#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_not_allow_packet 
	{
	public:
		int32_t cmd{};
	public:
		int32_t limit_time{};

	public:
		mrpcs_not_allow_packet()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cmd);
			protocol::SerializeType(pBuffer, &limit_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
