#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_build_tool_branch 
	{
	public:
		std::string name{};
	public:
		std::string url{};

	public:
		mrpcs_build_tool_branch()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &url);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
