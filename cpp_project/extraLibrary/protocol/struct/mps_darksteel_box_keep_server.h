#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_darksteel_box_keep_server 
	{
	public:
		int32_t gid{};
	public:
		uint8_t rank{};
	public:
		int64_t total{};

	public:
		mps_darksteel_box_keep_server()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &total);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
