#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_kick_user_info 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t server_index{};

	public:
		mrpcs_kick_user_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &server_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
