#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_teleport_area 
	{
	public:
		int32_t map_id{};
	public:
		int32_t tile_index{};
	public:
		float x{};
	public:
		float y{};
	public:
		float z{};

	public:
		mrpcs_teleport_area()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &map_id);
			protocol::SerializeType(pBuffer, &tile_index);
			protocol::SerializeType(pBuffer, &x);
			protocol::SerializeType(pBuffer, &y);
			protocol::SerializeType(pBuffer, &z);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
