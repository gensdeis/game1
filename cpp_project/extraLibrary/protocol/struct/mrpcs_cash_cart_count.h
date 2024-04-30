#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_cash_cart_count 
	{
	public:
		int32_t tid{};
	public:
		int32_t update_count{};

	public:
		mrpcs_cash_cart_count()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &update_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
