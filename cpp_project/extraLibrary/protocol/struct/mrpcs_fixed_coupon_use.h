#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_fixed_coupon_use 
	{
	public:
		int32_t seq{};
	public:
		std::vector<int64_t> list_auid{};

	public:
		mrpcs_fixed_coupon_use()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &seq);
			protocol::SerializeType(pBuffer, &list_auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
