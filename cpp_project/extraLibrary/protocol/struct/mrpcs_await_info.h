#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_await_info 
	{
	public:
		mpe_error error_code{};
	public:
		int32_t awaiter_count{};

	public:
		mrpcs_await_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &error_code);
			protocol::SerializeType(pBuffer, &awaiter_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
