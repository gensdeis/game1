#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_rpc_redis_login_character 
	{
	public:
		int32_t gid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		mrpce_login_character_flag flag{};
	public:
		std::string username{};
	public:
		std::string nickname{};
	public:
		int32_t id{};
	public:
		int32_t level{};
	public:
		int32_t lasttime{};

	public:
		mrpcs_rpc_redis_login_character()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &lasttime);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
