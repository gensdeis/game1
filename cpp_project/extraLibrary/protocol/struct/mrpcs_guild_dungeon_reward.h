#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_guild_dungeon_reward 
	{
	public:
		int64_t cuid{};
	public:
		int32_t reward_ratio{};
	public:
		std::vector<int32_t> list_accruedamage_reward_id{};
	public:
		std::vector<int32_t> list_join_reward_id{};

	public:
		mrpcs_guild_dungeon_reward()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &reward_ratio);
			protocol::SerializeType(pBuffer, &list_accruedamage_reward_id);
			protocol::SerializeType(pBuffer, &list_join_reward_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
