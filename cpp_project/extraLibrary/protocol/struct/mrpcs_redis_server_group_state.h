#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_redis_server_group_state 
	{
	public:
		int32_t gid{};
	public:
		int32_t await_max_count{};
	public:
		int32_t current_user_count{};
	public:
		int32_t server_state{};

	public:
		mrpcs_redis_server_group_state()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &await_max_count);
			protocol::SerializeType(pBuffer, &current_user_count);
			protocol::SerializeType(pBuffer, &server_state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
