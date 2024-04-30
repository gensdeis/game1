#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_event_info 
	{
	public:
		int32_t event_id{};
	public:
		int32_t reward_sequence{};
	public:
		int32_t last_reward_date{};

	public:
		mps_event_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &event_id);
			protocol::SerializeType(pBuffer, &reward_sequence);
			protocol::SerializeType(pBuffer, &last_reward_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
