#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_exchange_item_history 	// 거래소 정산 아이템
	{
	public:
		int64_t euid{};
	public:
		int32_t tid{};	// 아이템 아이디
	public:
		int32_t price{};	// 판매금액
	public:
		int32_t tax{};	// 세금
	public:
		int32_t stax{};	// 세금
	public:
		int32_t gold{};	// 정산금액
	public:
		uint16_t count{};	// 개수
	public:
		uint16_t reinforce{};	// 강화수치
	public:
		int32_t datetime{};	// 정산시간
	public:
		int32_t awaken_step{};	// 각성단계

	public:
		mps_exchange_item_history()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &price);
			protocol::SerializeType(pBuffer, &tax);
			protocol::SerializeType(pBuffer, &stax);
			protocol::SerializeType(pBuffer, &gold);
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
