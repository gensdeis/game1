#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mgms_base_guild_info 
	{
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		int64_t master_cuid{};
	public:
		std::string master_name{};
	public:
		int64_t create_time{};

	public:
		mgms_base_guild_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &master_cuid);
			protocol::SerializeType(pBuffer, &master_name);
			protocol::SerializeType(pBuffer, &create_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
