#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_login_server_group_info 
	{
	public:
		int32_t gid{};
	public:
		std::string name{};
	public:
		mpe_state state{};
	public:
		uint8_t recommend{};
	public:
		uint8_t new_server{};
	public:
		uint8_t create_limit{};
	public:
		uint8_t show_list{};
	public:
		uint8_t connect_limit{};
	public:
		int32_t server_state{};

	public:
		mps_login_server_group_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &recommend);
			protocol::SerializeType(pBuffer, &new_server);
			protocol::SerializeType(pBuffer, &create_limit);
			protocol::SerializeType(pBuffer, &show_list);
			protocol::SerializeType(pBuffer, &connect_limit);
			protocol::SerializeType(pBuffer, &server_state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
