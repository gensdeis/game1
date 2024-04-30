#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_zone_info 
	{
	public:
		int32_t id{};
	public:
		float x{};
	public:
		float y{};
	public:
		float z{};

	public:
		mps_zone_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &x);
			protocol::SerializeType(pBuffer, &y);
			protocol::SerializeType(pBuffer, &z);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
