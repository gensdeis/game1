#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_sector_info 
	{
	public:
		int32_t sector_id{};
	public:
		int32_t count{};	// 인원수

	public:
		mps_sector_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &sector_id);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
