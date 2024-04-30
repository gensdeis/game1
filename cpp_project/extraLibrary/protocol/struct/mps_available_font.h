#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_available_font 
	{
	public:
		int32_t start_range{};
	public:
		int32_t end_range{};

	public:
		mps_available_font()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &start_range);
			protocol::SerializeType(pBuffer, &end_range);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
