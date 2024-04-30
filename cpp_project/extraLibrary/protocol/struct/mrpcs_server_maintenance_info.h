#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_server_maintenance_info 
	{
	public:
		int32_t gid{};
	public:
		int64_t start_time{};
	public:
		int64_t end_time{};
	public:
		std::string admin_title{};
	public:
		std::string title{};
	public:
		std::string notice_body{};
	public:
		std::string notice_url{};
	public:
		std::string notice_edit_url{};
	public:
		int32_t kick_sec{};
	public:
		int64_t create_time{};

	public:
		mrpcs_server_maintenance_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &start_time);
			protocol::SerializeType(pBuffer, &end_time);
			protocol::SerializeType(pBuffer, &admin_title);
			protocol::SerializeType(pBuffer, &title);
			protocol::SerializeType(pBuffer, &notice_body);
			protocol::SerializeType(pBuffer, &notice_url);
			protocol::SerializeType(pBuffer, &notice_edit_url);
			protocol::SerializeType(pBuffer, &kick_sec);
			protocol::SerializeType(pBuffer, &create_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
