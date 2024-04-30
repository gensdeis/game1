#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_server_inspection 
	{
	public:
		int32_t seq{};
	public:
		std::string title_text{};
	public:
		int32_t platform_start_time_0{};
	public:
		int32_t platform_end_time_0{};
	public:
		int32_t platform_start_time_1{};
	public:
		int32_t platform_end_time_1{};
	public:
		int32_t platform_start_time_2{};
	public:
		int32_t platform_end_time_2{};
	public:
		int32_t platform_start_time_3{};
	public:
		int32_t platform_end_time_3{};
	public:
		std::string content_text{};
	public:
		std::string notice_url{};
	public:
		std::string patch_url{};
	public:
		int32_t user_kick_time{};
	public:
		int32_t reg_date{};
	public:
		std::string reg_user{};

	public:
		mrpcs_server_inspection()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &seq);
			protocol::SerializeType(pBuffer, &title_text);
			protocol::SerializeType(pBuffer, &platform_start_time_0);
			protocol::SerializeType(pBuffer, &platform_end_time_0);
			protocol::SerializeType(pBuffer, &platform_start_time_1);
			protocol::SerializeType(pBuffer, &platform_end_time_1);
			protocol::SerializeType(pBuffer, &platform_start_time_2);
			protocol::SerializeType(pBuffer, &platform_end_time_2);
			protocol::SerializeType(pBuffer, &platform_start_time_3);
			protocol::SerializeType(pBuffer, &platform_end_time_3);
			protocol::SerializeType(pBuffer, &content_text);
			protocol::SerializeType(pBuffer, &notice_url);
			protocol::SerializeType(pBuffer, &patch_url);
			protocol::SerializeType(pBuffer, &user_kick_time);
			protocol::SerializeType(pBuffer, &reg_date);
			protocol::SerializeType(pBuffer, &reg_user);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
