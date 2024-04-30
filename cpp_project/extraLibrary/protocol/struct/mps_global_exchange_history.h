#pragma once
#include <vector>
#include <string>
#include "mps_global_exchange_item_history.h"

namespace mir3d
{
	class mps_global_exchange_history 	// 거래소 정산내역
	{
	public:
		int32_t sell_count{};	// 판매횟수
	public:
		float sell_total{};	// 정산총액
	public:
		int32_t buy_count{};	// 구매횟수
	public:
		float buy_total{};	// 구매총액
	public:
		std::vector<mps_global_exchange_item_history> list{};

	public:
		mps_global_exchange_history()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &sell_count);
			protocol::SerializeType(pBuffer, &sell_total);
			protocol::SerializeType(pBuffer, &buy_count);
			protocol::SerializeType(pBuffer, &buy_total);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
