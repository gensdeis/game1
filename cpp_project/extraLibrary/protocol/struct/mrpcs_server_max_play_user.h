#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_server_max_play_user 
	{
	public:
		mrpce_server_type server_type{};
	public:
		int32_t server_index{};
	public:
		short max_play_user{};
	public:
		short current_play_user{};

	public:
		mrpcs_server_max_play_user()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeType(pBuffer, &max_play_user);
			protocol::SerializeType(pBuffer, &current_play_user);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
