#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_channel_ccu_info 
	{
	public:
		int64_t channel_uid{};
	public:
		short user_count{};

	public:
		mrpcs_channel_ccu_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &user_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
