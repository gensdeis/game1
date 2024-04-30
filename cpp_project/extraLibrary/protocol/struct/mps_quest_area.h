#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_quest_area 
	{
	public:
		int32_t area_id{};
	public:
		int32_t area_quest_finish_count{};

	public:
		mps_quest_area()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &area_id);
			protocol::SerializeType(pBuffer, &area_quest_finish_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
