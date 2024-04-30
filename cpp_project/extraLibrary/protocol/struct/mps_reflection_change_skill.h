#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_reflection_change_skill 
	{
	public:
		int32_t skill_id{};
	public:
		int32_t remain_cool_time{};

	public:
		mps_reflection_change_skill()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &skill_id);
			protocol::SerializeType(pBuffer, &remain_cool_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
