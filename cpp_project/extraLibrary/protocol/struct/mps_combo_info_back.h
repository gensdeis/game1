#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_combo_info_back 
	{
	public:
		int32_t skill_id{};
	public:
		int32_t slot_level{};
	public:
		int32_t effect{};

	public:
		mps_combo_info_back()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &skill_id);
			protocol::SerializeType(pBuffer, &slot_level);
			protocol::SerializeType(pBuffer, &effect);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
