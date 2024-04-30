#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_region_status_server 
	{
	public:
		uint8_t region{};
	public:
		std::string ip{};
	public:
		int32_t port{};

	public:
		mps_region_status_server()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &region);
			protocol::SerializeType(pBuffer, &ip);
			protocol::SerializeType(pBuffer, &port);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
