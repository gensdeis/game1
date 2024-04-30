#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_mentor_request 
	{
	public:
		int64_t cuid{};
	public:
		int64_t expire_time{};

	public:
		mrpcs_mentor_request()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &expire_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
