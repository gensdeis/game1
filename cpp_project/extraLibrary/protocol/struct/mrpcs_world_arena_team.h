#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_world_arena_team 
	{
	public:
		int64_t cuid{};
	public:
		int32_t gid{};

	public:
		mrpcs_world_arena_team()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
