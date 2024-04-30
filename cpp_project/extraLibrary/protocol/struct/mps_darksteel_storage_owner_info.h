#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_darksteel_storage_owner_info 
	{
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		mpe_occupationwar_map_type type{};
	public:
		std::vector<int64_t> list_good{};

	public:
		mps_darksteel_storage_owner_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &list_good);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
