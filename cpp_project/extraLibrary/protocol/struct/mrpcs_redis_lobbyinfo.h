#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_redis_lobbyinfo 
	{
	public:
		uint16_t gid{};
	public:
		int32_t index{};
	public:
		std::string name{};
	public:
		std::string server_url{};
	public:
		std::string service_url{};
	public:
		std::string cashshop_url{};
	public:
		std::string ping_ip{};
	public:
		int32_t ping_port{};
	public:
		std::string gate_ip{};
	public:
		int32_t gate_port{};
	public:
		int32_t state{};
	public:
		int32_t update_time{};
	public:
		std::string ip{};
	public:
		int32_t port{};

	public:
		mrpcs_redis_lobbyinfo()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &server_url);
			protocol::SerializeType(pBuffer, &service_url);
			protocol::SerializeType(pBuffer, &cashshop_url);
			protocol::SerializeType(pBuffer, &ping_ip);
			protocol::SerializeType(pBuffer, &ping_port);
			protocol::SerializeType(pBuffer, &gate_ip);
			protocol::SerializeType(pBuffer, &gate_port);
			protocol::SerializeType(pBuffer, &state);
			protocol::SerializeType(pBuffer, &update_time);
			protocol::SerializeType(pBuffer, &ip);
			protocol::SerializeType(pBuffer, &port);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
