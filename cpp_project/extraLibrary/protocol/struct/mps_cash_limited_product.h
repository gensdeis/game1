#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_cash_limited_product 
	{
	public:
		int32_t tid{};
	public:
		int32_t limit_date{};	// 종료시간
	public:
		uint16_t buy_count{};
	public:
		int32_t cart_count{};

	public:
		mps_cash_limited_product()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &limit_date);
			protocol::SerializeType(pBuffer, &buy_count);
			protocol::SerializeType(pBuffer, &cart_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
