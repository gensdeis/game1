#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mgms_gmserver_info 
	{
	public:
		int32_t gid{};
	public:
		std::string name{};
	public:
		std::string url{};
	public:
		std::string ip{};
	public:
		int32_t port{};
	public:
		int32_t update_time{};

	public:
		mgms_gmserver_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &url);
			protocol::SerializeType(pBuffer, &ip);
			protocol::SerializeType(pBuffer, &port);
			protocol::SerializeType(pBuffer, &update_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
