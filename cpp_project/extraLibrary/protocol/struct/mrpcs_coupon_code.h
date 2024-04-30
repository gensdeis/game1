#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_coupon_code 
	{
	public:
		std::string code{};
	public:
		int32_t seq{};

	public:
		mrpcs_coupon_code()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &code);
			protocol::SerializeType(pBuffer, &seq);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
