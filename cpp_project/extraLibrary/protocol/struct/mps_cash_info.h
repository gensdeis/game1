#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_cash_info 
	{
	public:
		int32_t cash{};	// 점권
	public:
		int32_t month_charge{};	// 월충전액(성인 : -1)
	public:
		int32_t last_charge{};	// 마지막충전일
	public:
		int32_t mileage{};	// 마일리지(표국주화)

	public:
		mps_cash_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cash);
			protocol::SerializeType(pBuffer, &month_charge);
			protocol::SerializeType(pBuffer, &last_charge);
			protocol::SerializeType(pBuffer, &mileage);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
