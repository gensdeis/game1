#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_dungeon_member_damage 
	{
	public:
		int64_t cuid{};
	public:
		int32_t damage{};

	public:
		mps_guild_dungeon_member_damage()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &damage);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
