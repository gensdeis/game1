#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_server_inspection 
	{
	public:
		std::string title_text{};
	public:
		int32_t start_time{};
	public:
		int32_t end_time{};
	public:
		std::string content_text{};
	public:
		std::string notice_url{};
	public:
		std::string patch_url{};

	public:
		mps_server_inspection()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &title_text);
			protocol::SerializeType(pBuffer, &start_time);
			protocol::SerializeType(pBuffer, &end_time);
			protocol::SerializeType(pBuffer, &content_text);
			protocol::SerializeType(pBuffer, &notice_url);
			protocol::SerializeType(pBuffer, &patch_url);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
