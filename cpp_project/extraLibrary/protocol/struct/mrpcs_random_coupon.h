#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_random_coupon 
	{
	public:
		std::string code{};
	public:
		int64_t auid{};

	public:
		mrpcs_random_coupon()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &code);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
