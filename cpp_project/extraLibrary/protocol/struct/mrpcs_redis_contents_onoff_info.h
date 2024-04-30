#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_redis_contents_onoff_info 
	{
	public:
		int32_t gid{};
	public:
		int32_t contents_type{};
	public:
		std::string param{};
	public:
		std::string active{};

	public:
		mrpcs_redis_contents_onoff_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &contents_type);
			protocol::SerializeType(pBuffer, &param);
			protocol::SerializeType(pBuffer, &active);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
