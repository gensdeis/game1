#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_treasurebox_reward_item 
	{
	public:
		int32_t item_id{};
	public:
		int32_t count{};

	public:
		mps_guild_treasurebox_reward_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &item_id);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
