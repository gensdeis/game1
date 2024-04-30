#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_player_login_info 
	{
	public:
		int64_t auid{};
	public:
		int32_t gid{};
	public:
		int64_t access_token{};
	public:
		int32_t login_time{};

	public:
		mrpcs_player_login_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &login_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
