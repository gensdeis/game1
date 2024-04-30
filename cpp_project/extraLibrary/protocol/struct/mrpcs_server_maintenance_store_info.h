#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_server_maintenance_store_info 
	{
	public:
		int32_t gid{};
	public:
		int32_t store_type{};
	public:
		int64_t start_time{};
	public:
		int64_t end_time{};
	public:
		std::string text_body{};
	public:
		std::string text_url{};
	public:
		std::string text_edit_url{};
	public:
		int64_t create_time{};

	public:
		mrpcs_server_maintenance_store_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &store_type);
			protocol::SerializeType(pBuffer, &start_time);
			protocol::SerializeType(pBuffer, &end_time);
			protocol::SerializeType(pBuffer, &text_body);
			protocol::SerializeType(pBuffer, &text_url);
			protocol::SerializeType(pBuffer, &text_edit_url);
			protocol::SerializeType(pBuffer, &create_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
