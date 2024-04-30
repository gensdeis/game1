#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_redis_rpcinfo 
	{
	public:
		mrpce_server_type type{};
	public:
		int32_t svn_revision_number{};
	public:
		std::string version_number{};
	public:
		std::string table_version_number{};
	public:
		int32_t gid{};
	public:
		int32_t index{};
	public:
		std::string server_name{};
	public:
		std::string ip{};
	public:
		uint16_t port{};
	public:
		std::string url{};
	public:
		int32_t user_cnt{};
	public:
		int32_t zone_cnt{};
	public:
		std::string rpc_session_info{};
	public:
		uint8_t state{};
	public:
		int32_t update_time{};
	public:
		std::string observer{};
	public:
		int32_t connected_socket_size{};
	public:
		int32_t max_socket_size{};
	public:
		int32_t ghost_socket_size{};
	public:
		int32_t session_user_cnt{};
	public:
		int32_t waiting_seesion_pool_size{};
	public:
		int32_t disconnect_seesion_pool_size{};

	public:
		mrpcs_redis_rpcinfo()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &svn_revision_number);
			protocol::SerializeType(pBuffer, &version_number);
			protocol::SerializeType(pBuffer, &table_version_number);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &server_name);
			protocol::SerializeType(pBuffer, &ip);
			protocol::SerializeType(pBuffer, &port);
			protocol::SerializeType(pBuffer, &url);
			protocol::SerializeType(pBuffer, &user_cnt);
			protocol::SerializeType(pBuffer, &zone_cnt);
			protocol::SerializeType(pBuffer, &rpc_session_info);
			protocol::SerializeType(pBuffer, &state);
			protocol::SerializeType(pBuffer, &update_time);
			protocol::SerializeType(pBuffer, &observer);
			protocol::SerializeType(pBuffer, &connected_socket_size);
			protocol::SerializeType(pBuffer, &max_socket_size);
			protocol::SerializeType(pBuffer, &ghost_socket_size);
			protocol::SerializeType(pBuffer, &session_user_cnt);
			protocol::SerializeType(pBuffer, &waiting_seesion_pool_size);
			protocol::SerializeType(pBuffer, &disconnect_seesion_pool_size);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
