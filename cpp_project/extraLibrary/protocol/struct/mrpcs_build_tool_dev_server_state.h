#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_build_tool_dev_server_state 
	{
	public:
		int32_t index{};
	public:
		bool on{};

	public:
		mrpcs_build_tool_dev_server_state()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &on);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
