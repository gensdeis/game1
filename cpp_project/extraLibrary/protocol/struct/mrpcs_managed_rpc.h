#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_managed_rpc 
	{
	public:
		std::string key{};
	public:
		std::string info{};

	public:
		mrpcs_managed_rpc()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
