#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_occupationwar_war_map_info 
	{
	public:
		mpe_occupationwar_map_type map_type{};
	public:
		std::vector<int64_t> list_guid{};

	public:
		mrpcs_occupationwar_war_map_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &map_type);
			protocol::SerializeType(pBuffer, &list_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
