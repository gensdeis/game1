#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_vector2d 
	{
	public:
		int32_t x{};
	public:
		int32_t y{};

	public:
		mps_vector2d()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &x);
			protocol::SerializeType(pBuffer, &y);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
