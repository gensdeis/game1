#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_login_lobby_info 
	{
	public:
		std::string url{};

	public:
		mps_login_lobby_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &url);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
