#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_server_relocation_list 
	{
	public:
		int32_t gid{};
	public:
		uint8_t state{};
	public:
		uint8_t send_state{};
	public:
		uint8_t receive_state{};
	public:
		int32_t max_user_count{};
	public:
		int32_t current_user_count{};

	public:
		mps_server_relocation_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &state);
			protocol::SerializeType(pBuffer, &send_state);
			protocol::SerializeType(pBuffer, &receive_state);
			protocol::SerializeType(pBuffer, &max_user_count);
			protocol::SerializeType(pBuffer, &current_user_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
