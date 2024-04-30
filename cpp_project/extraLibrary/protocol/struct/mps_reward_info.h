#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_reward_info 
	{
	public:
		int32_t npc_id{};
	public:
		uint16_t reward{};

	public:
		mps_reward_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &npc_id);
			protocol::SerializeType(pBuffer, &reward);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
