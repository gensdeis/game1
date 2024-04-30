#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_cash_package_product 
	{
	public:
		int32_t tid{};
	public:
		int32_t index{};	// 꾸러미 : index / 성장꾸러미 : bit 연산
	public:
		int32_t sub_index{};	// 성장꾸러미전용(bit)
	public:
		int32_t expire_time{};	// 만료일
	public:
		int32_t last_buy_time{};	// 마지막 구매일

	public:
		mps_cash_package_product()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &sub_index);
			protocol::SerializeType(pBuffer, &expire_time);
			protocol::SerializeType(pBuffer, &last_buy_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
