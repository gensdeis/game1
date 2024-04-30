#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_config_database 
	{
	public:
		std::string name{};
	public:
		std::string ip{};
	public:
		int32_t port{};
	public:
		std::string db{};
	public:
		std::string user{};
	public:
		std::string passwd{};
	public:
		int32_t pool_min_size{};
	public:
		int32_t pool_max_size{};
	public:
		int32_t connection_timeout{};
	public:
		std::string character_set{};
	public:
		int64_t cache_time{};

	public:
		mrpcs_config_database()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &ip);
			protocol::SerializeType(pBuffer, &port);
			protocol::SerializeType(pBuffer, &db);
			protocol::SerializeType(pBuffer, &user);
			protocol::SerializeType(pBuffer, &passwd);
			protocol::SerializeType(pBuffer, &pool_min_size);
			protocol::SerializeType(pBuffer, &pool_max_size);
			protocol::SerializeType(pBuffer, &connection_timeout);
			protocol::SerializeType(pBuffer, &character_set);
			protocol::SerializeType(pBuffer, &cache_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
