#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_special_move 
	{
	public:
		int32_t skill_id{};
	public:
		int32_t slot_level{};

	public:
		mps_special_move()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &skill_id);
			protocol::SerializeType(pBuffer, &slot_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
