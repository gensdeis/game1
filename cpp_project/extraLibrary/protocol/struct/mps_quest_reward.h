#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_quest_reward 
	{
	public:
		uint16_t quest_id{};
	public:
		std::vector<int32_t> reward_tid{};

	public:
		mps_quest_reward()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &quest_id);
			protocol::SerializeType(pBuffer, &reward_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
