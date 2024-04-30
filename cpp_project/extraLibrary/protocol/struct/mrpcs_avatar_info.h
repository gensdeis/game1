#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_avatar_info 
	{
	public:
		int32_t id{};
	public:
		int32_t expire_time{};

	public:
		mrpcs_avatar_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &expire_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
