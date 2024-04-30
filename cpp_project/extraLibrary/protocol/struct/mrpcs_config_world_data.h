#pragma once
#include <vector>
#include <string>
#include "mrpcs_config_redis.h"
#include "mrpcs_config_redis.h"
#include "mrpcs_config_redis.h"
#include "mrpcs_config_database.h"

namespace mir3d
{
	class mrpcs_config_world_data 
	{
	public:
		int32_t gid{};
	public:
		int32_t update_time{};
	private:
		bool flag_redis_community = false;
		mrpcs_config_redis redis_community;
		mrpcs_config_redis* p_redis_community = nullptr;
	public:
		bool has_redis_community() const
		{
			return flag_redis_community;
		}
		mrpcs_config_redis* alloc_redis_community()
		{
			flag_redis_community = true;
			return &redis_community;
		}
		const mrpcs_config_redis* get_redis_community() const
		{
			if (true == flag_redis_community)
			{
				if (nullptr == p_redis_community)
				{
					return &redis_community;
				}
				return p_redis_community;
			}
			return nullptr;
		}
		void set_redis_community(mrpcs_config_redis* in_redis_community)
		{
			if (nullptr == p_redis_community)
			{
				p_redis_community = in_redis_community;
				flag_redis_community = true;
			}
		}
	private:
		bool flag_redis_lobby = false;
		mrpcs_config_redis redis_lobby;
		mrpcs_config_redis* p_redis_lobby = nullptr;
	public:
		bool has_redis_lobby() const
		{
			return flag_redis_lobby;
		}
		mrpcs_config_redis* alloc_redis_lobby()
		{
			flag_redis_lobby = true;
			return &redis_lobby;
		}
		const mrpcs_config_redis* get_redis_lobby() const
		{
			if (true == flag_redis_lobby)
			{
				if (nullptr == p_redis_lobby)
				{
					return &redis_lobby;
				}
				return p_redis_lobby;
			}
			return nullptr;
		}
		void set_redis_lobby(mrpcs_config_redis* in_redis_lobby)
		{
			if (nullptr == p_redis_lobby)
			{
				p_redis_lobby = in_redis_lobby;
				flag_redis_lobby = true;
			}
		}
	private:
		bool flag_redis_world = false;
		mrpcs_config_redis redis_world;
		mrpcs_config_redis* p_redis_world = nullptr;
	public:
		bool has_redis_world() const
		{
			return flag_redis_world;
		}
		mrpcs_config_redis* alloc_redis_world()
		{
			flag_redis_world = true;
			return &redis_world;
		}
		const mrpcs_config_redis* get_redis_world() const
		{
			if (true == flag_redis_world)
			{
				if (nullptr == p_redis_world)
				{
					return &redis_world;
				}
				return p_redis_world;
			}
			return nullptr;
		}
		void set_redis_world(mrpcs_config_redis* in_redis_world)
		{
			if (nullptr == p_redis_world)
			{
				p_redis_world = in_redis_world;
				flag_redis_world = true;
			}
		}
	private:
		bool flag_database = false;
		mrpcs_config_database database;
		mrpcs_config_database* p_database = nullptr;
	public:
		bool has_database() const
		{
			return flag_database;
		}
		mrpcs_config_database* alloc_database()
		{
			flag_database = true;
			return &database;
		}
		const mrpcs_config_database* get_database() const
		{
			if (true == flag_database)
			{
				if (nullptr == p_database)
				{
					return &database;
				}
				return p_database;
			}
			return nullptr;
		}
		void set_database(mrpcs_config_database* in_database)
		{
			if (nullptr == p_database)
			{
				p_database = in_database;
				flag_database = true;
			}
		}

	public:
		mrpcs_config_world_data()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &update_time);
			protocol::SerializeType(pBuffer, &flag_redis_community);
			if (true == flag_redis_community)
			{
				if (nullptr != p_redis_community)
					protocol::SerializeType(pBuffer, p_redis_community);
				else
					protocol::SerializeType(pBuffer, &redis_community);
			}
			protocol::SerializeType(pBuffer, &flag_redis_lobby);
			if (true == flag_redis_lobby)
			{
				if (nullptr != p_redis_lobby)
					protocol::SerializeType(pBuffer, p_redis_lobby);
				else
					protocol::SerializeType(pBuffer, &redis_lobby);
			}
			protocol::SerializeType(pBuffer, &flag_redis_world);
			if (true == flag_redis_world)
			{
				if (nullptr != p_redis_world)
					protocol::SerializeType(pBuffer, p_redis_world);
				else
					protocol::SerializeType(pBuffer, &redis_world);
			}
			protocol::SerializeType(pBuffer, &flag_database);
			if (true == flag_database)
			{
				if (nullptr != p_database)
					protocol::SerializeType(pBuffer, p_database);
				else
					protocol::SerializeType(pBuffer, &database);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
