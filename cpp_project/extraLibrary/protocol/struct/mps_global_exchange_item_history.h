#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_global_exchange_item_history 	// 거래소 정산 아이템
	{
	public:
		int64_t euid{};
	public:
		mpe_exchange_history_type type{};
	public:
		int32_t tid{};	// 아이템 아이디
	public:
		float price{};	// 판매금액
	public:
		float tax{};	// 세금
	public:
		float sell_price{};	// 정산금액
	public:
		float buy_price{};	// 구매금액
	public:
		uint16_t count{};	// 개수
	public:
		uint8_t reinforce{};	// 강화수치
	public:
		int32_t datetime{};	// 처리시간
	public:
		int32_t awaken_step{};	// 각성단계

	public:
		mps_global_exchange_item_history()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &price);
			protocol::SerializeType(pBuffer, &tax);
			protocol::SerializeType(pBuffer, &sell_price);
			protocol::SerializeType(pBuffer, &buy_price);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &reinforce);
			protocol::SerializeType(pBuffer, &datetime);
			protocol::SerializeType(pBuffer, &awaken_step);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
