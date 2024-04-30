#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_map_discovery 
	{
	public:
		int32_t map_id{};
	public:
		std::vector<int64_t> list_area{};

	public:
		mps_map_discovery()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &map_id);
			protocol::SerializeType(pBuffer, &list_area);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
