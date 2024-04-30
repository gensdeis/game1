#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_build_tool_dev_server 
	{
	public:
		int32_t index{};
	public:
		std::string ip{};
	public:
		int32_t port{};

	public:
		mrpcs_build_tool_dev_server()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &ip);
			protocol::SerializeType(pBuffer, &port);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
